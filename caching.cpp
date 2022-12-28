#include <iostream>
#include <cstring>
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

struct customCompare {
    bool operator() (const pair<long, long> &a, const pair<long, long> &b) const {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    long cacheStorage; cin >> cacheStorage;
    long objectsNum; cin >> objectsNum;
    long accessNum; cin >> accessNum;
    long count = 0;

    //pair<long, long> object[objectsNum]; //instead of using unordered_map
    long noOfAccess[objectsNum]; //after each access, decrease by 1
    for (long i = 0; i < objectsNum; i++) {
        noOfAccess[i] = accessNum;
    }
    //the higher the value in pq_access, the lower the priority
    set<pair<long, long>> cache;
    vector<long> accessObj; //has accessNum objs
    long pq_access[accessNum];
    for (long i = 0; i < accessNum; i++) {
        long obj; cin >> obj;
        accessObj.push_back(obj);
    }
    bool check[objectsNum] = {false};
    for (long i = accessNum-1; i >= 0; i--) {
        //noOfAccess[accessObj[i]] -= 1;
        pq_access[i] = --noOfAccess[accessObj[i]];
    }
    // for (long i = 0; i < accessNum; i++) {
    //     cout << pq_access[i] << ' ';
    // }
    
    // if one object is accessed continuously, let the number of count += 1 only



    cout << count; 

    return 0;
}