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
#include <set> 
#include <map>

using namespace std;

// class Task {
// public:
//     long energy;
//     long gold;

//     Task(long _energy, long _gold) {
//         energy = _energy;
//         gold = _gold;
//     }
// };

// bool sortTask(const Task &a, const Task &b) {
//     if (a.energy != b.energy) {
//         return a.energy > b.energy;
//     }
//     return a.gold > b.gold;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n; cin >> n;
    map<long, priority_queue<long>> map; //for each task, map energy and priority_queue of gold
    for (long i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            long energy, gold;
            cin >> energy >> gold;
            if (map.find(energy) == map.end()) { //cannot find this value in map
                priority_queue<long> p;
                p.push(gold);
                map[energy] = p;
            } else { //already mapped the energy value to a PQ
                auto find = map.find(energy);
                find->second.push(gold);
            }
        } else { //cmd == "query"
            long x, totalGold = 0;
            cin >> x;
            while (!map.empty()) { //check if there is any value that smaller than x in the map
                auto find = map.lower_bound(x);
                if (find == map.end()) { 
                    // when there is no value that no less than x then the iterator will return the past-the-last element
                    // then every element will be smaller than x
                    find--;
                    x -= find->first;
                    totalGold+= find->second.top();
                    find->second.pop();
                    if (find->second.empty()) {
                        map.erase(find);
                    }
                } else { //find != map.end();
                    while (find->first > x && find != map.begin()) {
                        find--;
                    }
                    if (find->first > x) {
                        break;
                    } else {
                        totalGold+= find->second.top();
                        x -= find->first;
                        find->second.pop();
                        if (find->second.empty()) {
                            map.erase(find);
                        }
                    }
                }
            }
            //     } else if (find == map.begin()) {
            //         if (find->first == x) {
            //             x -= find->first;
            //             totalGold+= find->second.top();
            //             find->second.pop();
            //             if (find->second.empty()) {
            //                 map.erase(find);
            //             }
            //             //cout << totalGold << '\n';
            //             break;
            //         } else if (find->first > x) {
            //             break;
            //         }   
            //     } else if (find != map.begin()) {
            //         --find;
            //         x -= find->first;
            //         totalGold+= find->second.top();
            //         find->second.pop();
            //         if (find->second.empty()) {
            //             map.erase(find);
            //         }
            //     }
            // }
            //check the remaining energy
            // auto find = map.find(x);
            // if (find != map.end()) { 
            //     totalGold += find->second.top();
            //     find->second.pop();
            //     if (find->second.empty()) {
            //         map.erase(find);
            //     }
            // }
            cout << totalGold << '\n';
        }
    }

    return 0;
}