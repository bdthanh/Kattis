//PL2_4M4R

/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, k; cin >>n >> k;
    map<long, long> map; 
    for (long i=0; i < n; i++) {
        long x; cin >> x; 
        auto it = map.find(x);
        if (it == map.end()) {
            map[x] = 1;
        } else {
            it->second+=1;
        }
    }
    priority_queue<long> count;
    for (auto&x: map) {
        count.push(x.second);
    }
    for (long i =0; i < k; i++) {
        if (count.top()!= 0) {
            long x = count.top(); x--;
            count.pop();
            count.push(x);
        }
    }
    cout << count.top();
    return 0;
}