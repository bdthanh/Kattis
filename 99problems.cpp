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

    long n, q; cin >> n >> q;
    multiset<long> problems; 
    for (long i = 0; i < n; i++) {
        long p; cin >> p;
        problems.insert(p);
    }
    for (long i = 0; i < q; i++) {
        long cmd, d; cin >> cmd >> d;
        if (cmd == 1) { //The easiest problem strictly harder than difficulty D
            auto it = problems.upper_bound(d); //an iterator to the first element greater than d
            if (it == problems.end()) {
                cout << -1 << '\n';
            } else {
                cout << *it << '\n';
                problems.erase(it);
            }
        } else { //cmd == 2: The hardest problem not harder than difficulty D -> x <= d
            auto it = problems.upper_bound(d); //an iterator to the first element greater than d -> *it > d
            if (it != problems.begin()) { // all problems <= d
                it--; 
                cout << *it << '\n';
                problems.erase(it);
            } else {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0;
}