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
#include <climits>

using namespace std; 
typedef long long ll;
const ll INF = 0xEEBE0B40E8000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll V, E ,c ,k , m; ll s = 0;
    cin >> V >> E >> c >> k >> m;

    vector<vector<pair<ll, ll>>> AL(V, vector<pair<ll, ll>>());
    for (ll i = 0; i < E; i++) {
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }

    vector<ll> dist(V, INF); dist[0] = 0;                 
    // (Modified) Dijkstra's algorithm
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    pq.push({0, s});

    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        auto [d, u] = pq.top(); pq.pop();            // shortest unvisited u
    if (d > dist[u]) continue;                   // a very important check
        for (auto &[v, w] : AL[u]) {                 // all edges from u
            if (dist[u]+w >= dist[v]) 
                continue;        // not improving, skip
            dist[v] = dist[u]+w;                       // relax operation
            pq.push({dist[v], v});                     // enqueue better pair
        }
    }

    vector<ll> sortedDist;
    for (ll i = 0; i < c; i++) {
        ll f; cin >> f; f--;
        if (dist[f] != INF) {
            sortedDist.push_back(dist[f]);
        }
    }

    sort(sortedDist.begin(), sortedDist.end());
    if (sortedDist.size() < m && k > m) { // impossible cases
        cout << -1;
    } else if (sortedDist.size() < m && sortedDist.size() < k) {
        cout << -1;
    } else {
        if (sortedDist.size() >= m) {
            if (k > m) {
                cout << 2*sortedDist[m-1];
            } else { //k <= m
                cout << 2*sortedDist[k-1];
            }
        } else if (sortedDist.size() < m) {
            if (k <= m) {
                cout << 2*sortedDist[k-1];
            }  else if (sortedDist.size() >= k) {
                cout << 2*sortedDist[k-1];
            }
        } 
    }

    return 0;
}