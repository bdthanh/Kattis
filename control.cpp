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
typedef vector<int> vi; /*****can change before use*****/

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
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
    UnionFind ingre(500002);
    long ans = 0;
    for (long i = 0; i < n; i ++) {
        long m; cin >> m;
        set<long> set;
        for (long j = 0; j < m; j++) {
            long ingredient; cin >> ingredient;ingredient++;
            long find = ingre.findSet(ingredient);     
            set.insert(find);  
        }
        long count = 0;
        for (auto& x: set) {
            count += ingre.sizeOfSet(x);
        }
        if (count == m) {
            ans++;
            long x = *(set.begin());
            for (auto &y: set) {
                ingre.unionSet(y, x);
            }
            //cout << i;
        }
    }

    cout << ans;
    
    return 0;
}