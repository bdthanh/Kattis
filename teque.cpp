#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std; 

//to check
void print(deque<long> &f, deque<long> &b) {
    cout << "front: ";
    for (auto &x: f) {
        cout << x << ' ';
    }
    cout << '\n' << "back: ";
    for (auto &x: b) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /***** get() in O(N) -> time limit *****/
    // list<long> list;
    // auto midPos = list.begin();
    // long n, size = 0; string commands;
    // cin >> n;
    // for (long i = 0; i < n; i++) {
    //     long num, idx;
    //     cin >> commands;
    //     if (commands == "push_front") {
    //         cin >> num;
    //         list.push_front(num); 
    //     } else if (commands == "push_back") {
    //         cin >> num;
    //         list.push_back(num);
    //     } else if (commands == "push_middle") {
    //         cin >> num;
    //         list.insert(midPos, num);
    //     } else if (commands == "get") {
    //         cin >> idx;
    //     }
    // }

    /***** use deque instead -> get() in O(1) *****/
    deque<long> front;
    deque<long> back;
    long n; string commands;
    cin >> n;
    for (long i = 0; i < n; i++) {
        long num, idx;
        cin >> commands;
        if (commands == "push_front") {
            cin >> num; 
            if (front.size() == back.size()) {
                front.push_front(num);
            } else if (front.size() - back.size() == 1) {
                front.push_front(num);
                num = front[front.size() - 1];
                front.pop_back();
                back.push_front(num);
            }
        } else if (commands == "push_back") {
            cin >> num;
            if (front.size() - back.size() == 1) {
                back.push_back(num);
            } else if (front.size() == back.size()) {
                back.push_back(num);
                num = back[0];
                back.pop_front();
                front.push_back(num);               
            }
        } else if (commands == "push_middle") {
            cin >> num;
            if ((front.size() + back.size()) % 2 == 0) {
                front.push_back(num);
            } else { //(front.size() + back.size()) % 2 == 1
                back.push_front(num);
            }
        } else if (commands == "get") {
            cin >> idx;
            if (front.size() > idx) {
                cout << front[idx] << '\n'; 
            } else {
                cout << back[idx - front.size()] << '\n';
            }
        }
    }
    return 0; 
}
