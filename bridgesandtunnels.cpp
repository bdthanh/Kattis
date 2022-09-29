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
class UnionFind {                                // OOP style
private:
  vector<long> p, rank, setSize;                         
  long numSets;
public:
  UnionFind(long N) {
    p.assign(N, 0); for (long i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  long findSet(long i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(long i, long j) { return findSet(i) == findSet(j); }

  long numDisjolongSets() { 
       return numSets; }      // optional
  long sizeOfSet(long i) { return setSize[findSet(i)]; } // optional

  void unionSet(long i, long j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    long x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n; cin >> n; 
    long id = 1;
    unordered_map<string, long> map;
    UnionFind cities(2*n);   
    for (long i= 0; i< n; i++) {
        string a, b; 
        cin >> a >> b;
        
        auto ita = map.find(a);
        auto itb = map.find(b);
        
        if (ita == map.end()) {
            map[a] = id;
            id++;
        }
        if (itb == map.end()) {
            map[b] = id;
            id++;
        }
        auto ita2 = map.find(a);
        auto itb2 = map.find(b);      
        cities.unionSet(ita2->second, itb2->second);
        cout << cities.sizeOfSet(ita2->second) << '\n';
    }
    
    return 0;
}