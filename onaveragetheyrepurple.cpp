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
    long V, E ; cin >> V >> E;
    vector<vector<pair<int, int>>> AL(V, vector<pair<int, int>>());
    for (long i = 0; i < E ;i++) {
        long a, b; cin >> a >> b;
        AL[a].emplace_back(b, 0);
        AL[b].emplace_back(a, 0);
    }
    
    return 0;
}