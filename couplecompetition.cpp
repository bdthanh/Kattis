/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <stack>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std; 

class Block {
public:
    long height;
    long pos;

    Block(long _height, long _pos) {
        height = _height;
        pos = _pos;
    }
};

bool compareBlockHeight (const Block &a, const Block &b) {
    return a.height < b.height;
}

int main() { // O(nlogn)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n; cin >> n;
    vector<long> height;
    vector<Block> sortedBlock;
    pair<long, long> higher[n];
    // pair->first: left higher block, pair->second: right higher block
    // if there is no higher then store -1
    long minJump[n] ;
    for (long i = 0;i < n; i++) {
        long h; cin >> h;
        height.push_back(h);
        sortedBlock.push_back(Block(h,i)); 
    }
    // find the left and right higher block using two stacks: 
    stack<Block> left;
    stack<Block> right;
    // at this moment, sortedBlock is not sorted yet 
    for (long i = 0; i < n; i++) {
        if (left.empty()) {
            left.push(sortedBlock[i]);
            higher[i].first = -1;
        } else { // !left.empty()
            while (!left.empty() && left.top().height <= sortedBlock[i].height) {
                left.pop();
            }
            if (left.empty()) {
                left.push(sortedBlock[i]);
                higher[i].first = -1;
            } else {
                higher[i].first = left.top().pos;
                left.push(sortedBlock[i]);
            }
        }
    }

    for (long i = n-1; i >= 0; i--) {
        if (right.empty()) {
            right.push(sortedBlock[i]);
            higher[i].second = -1;
        } else { // !right.empty()
            while (!right.empty() && right.top().height <= sortedBlock[i].height) {
                right.pop();
            }
            if (right.empty()) {
                right.push(sortedBlock[i]);
                higher[i].second = -1;
            } else {
                higher[i].second = right.top().pos;
                right.push(sortedBlock[i]);
            }
        }
    }

    sort(sortedBlock.begin(), sortedBlock.end(), compareBlockHeight); //sort block by their height 
    long check; 

    for (long i = n-1; i >= 0; i--) {
        if (sortedBlock[i].height == sortedBlock[n-1].height) { // all the highest block
            minJump[sortedBlock[i].pos] = 0;
            check = i;
        } else if (check >= 1 && (sortedBlock[i].height == sortedBlock[check-1].height)) { // second highest
            minJump[sortedBlock[i].pos] = 1;
        } else {
            if (higher[sortedBlock[i].pos].first == -1) { // no higher block on the left side 
                minJump[sortedBlock[i].pos] = 1 + minJump[higher[sortedBlock[i].pos].second];
            } else if (higher[sortedBlock[i].pos].second == -1) { // no higher block on the right side 
                minJump[sortedBlock[i].pos] = 1 + minJump[higher[sortedBlock[i].pos].first];
            } else { // both side have higher blocks
                if (minJump[higher[sortedBlock[i].pos].second] > minJump[higher[sortedBlock[i].pos].first]) {
                    minJump[sortedBlock[i].pos] = 1 + minJump[higher[sortedBlock[i].pos].first];
                } else {
                    minJump[sortedBlock[i].pos] = 1 + minJump[higher[sortedBlock[i].pos].second];
                }
            }
        }
    }

    for (long i = 0; i < n; i++) {
        cout << minJump[i] << ' ';
    }
    return 0;
}


// long findNearestHigherBlock(long curID, long n, vector<long> &height, long minJump[]) {
//     long findIDleft = curID-1;
//     long findIDright = curID+1;
//     while (findIDleft >= 0 && height[findIDleft] <= height[curID]) {
//         findIDleft--;
//     }
//     while (findIDright <= n - 1 && height[findIDright] <= height[curID]) {
//         findIDright++;
//     }
//     if (findIDleft == -1) {
//         return findIDright;
//     } else if (findIDright == n) {
//         return findIDleft;
//     } else {
//         if (minJump[findIDleft] > minJump[findIDright]) {
//             return findIDright;
//         }
//         return findIDleft;
//     }
// }

// int main() { // O(n^2)
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     long n; cin >> n;
//     vector<long> height;
//     vector<Block> sortedBlock;

//     long minJump[n] ;
//     for (long i = 0; i < n;i ++ ){
//         minJump[i] = -1;
//     }
//     for (long i = 0;i < n; i++) {
//         long h; cin >> h;
//         height.push_back(h);
//         sortedBlock.push_back(Block(h,i)); 
//     }
//     sort(sortedBlock.begin(), sortedBlock.end(), compareBlockHeight); //has n blocks
//     long check; 
//     for (long i = n-1; i >= 0; i--) {
//         if (sortedBlock[i].height == sortedBlock[n-1].height) {
//             minJump[sortedBlock[i].pos] = 0;
//             check = i;
//         } else if (check >= 1 && (sortedBlock[i].height == sortedBlock[check-1].height)) {
//             minJump[sortedBlock[i].pos] = 1;
//         } else {
//             long near = findNearestHigherBlock(sortedBlock[i].pos, n, height, minJump);
//             minJump[sortedBlock[i].pos] = 1 + minJump[near];
//             // cout << near << '\n';
//         }
//         // for (long i = 0; i < n; i++) {
//         //     cout << minJump[i] << ' ' ;
//         // }   
//         // cout << '\n';
//     }

//     for (long i = 0; i < n; i++) {
//         cout << minJump[i] << ' ';
//     }
//     return 0;
// }