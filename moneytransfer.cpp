#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, m; cin >> n >> m;
    unordered_map<string, long> umap;
    vector<string> names;
    for (long i = 0; i < n; i++ ) {
        long initB;
        string name; cin >> name >> initB; names.push_back(name);
        umap[name] = initB;
    }
    sort(names.begin(), names.end()); 
    for (long i = 0; i < m; i++) {
        string a, b; long val; cin >> a >> b >> val;
        auto ita = umap.find(a);
        auto itb = umap.find(b);
        if (ita == umap.end() || itb == umap.end() || val > ita->second) {
            //rejected --> do nothing
        } else {
            ita->second -= val;
            itb->second += val;
        }
    }

    for (long i = 0; i < n; i++) {
        auto it = umap.find(names[i]);
        cout << it->first << ' ' << it->second << '\n';
    }
    
    return 0;
}