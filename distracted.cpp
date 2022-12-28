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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, l; cin >> n >> l;
    string name; char s;
    unordered_map<string, char> map;
    for (long i = 0; i < n;i ++) {
        cin >> name >> s;
        map[name] = s;
    }
    string p1, p2, x;
    long count = 0;
    bool isDetermined = true;
    for (long i = 0; i < l; i++) {
        cin >> p1 >> x >> p2;
        auto it1 = map.find(p1);
        auto it2 = map.find(p2);
        if (it1->second == 'm' && it2->second == 'u') {
            isDetermined = true;
            count += 1;
        } 
        if (count == 0 && (it1->second == '?' || it2->second == '?')) {
            isDetermined = false;
        }
    }
    if (count > 0) cout << 1;
    else if (count == 0 && isDetermined) cout << 0;
    else if (count == 0 && !isDetermined) cout << '?';

    return 0;
}