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
  vector<long> p, rank, setSize;                           // vi p is the key part
  long numSets;
public:
  UnionFind(long N) {
    p.assign(N, 0); for (long i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  long  findSet(long  i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(long  i, long  j) { return findSet(i) == findSet(j); }

  long  numDisjointSets() { return numSets; }      // optional
  long  sizeOfSet(long  i) { return setSize[findSet(i)]; } // optional

  void unionSet(long  i, long  j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    long  x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

long location(long row, long col, long c) {
    return row*c+col;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long r, c; cin >> r >> c;
    char x[r][c];
    UnionFind uf(r*c);
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < c; j++) {
            cin >> x[i][j]; 
        }
    }
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < c; j++) {
            if (i != 0 && j != 0 && i != r-1 && j != c-1) {
                if (x[i][j] == x[i][j-1]) uf.unionSet(location(i, j, c), location(i, j-1, c));
                if (x[i][j] == x[i][j+1]) uf.unionSet(location(i, j, c), location(i, j+1, c));
                if (x[i][j] == x[i-1][j]) uf.unionSet(location(i, j, c), location(i-1, j, c));
                if (x[i][j] == x[i+1][j]) uf.unionSet(location(i, j, c), location(i+1, j, c));
            } else if (i == 0) {
                if (j == 0) {
                    if (x[i][j] == x[0][1]) uf.unionSet(location(i, j, c), location(0, 1, c));
                    if (x[i][j] == x[1][0]) uf.unionSet(location(i, j, c), location(1, 0, c));
                } else if (j == c - 1) {
                    if (x[i][j] == x[0][c-2]) uf.unionSet(location(i, j, c), location(0, c-2, c));
                    if (x[i][j] == x[1][c-1]) uf.unionSet(location(i, j, c), location(1, c-1, c));
                } else {
                    if (x[i][j] == x[0][j-1]) uf.unionSet(location(i, j, c), location(0, j-1, c));
                    if (x[i][j] == x[0][j+1]) uf.unionSet(location(i, j, c), location(0, j+1, c));
                    if (x[i][j] == x[1][j]) uf.unionSet(location(i, j, c), location(1, j, c));
                }
            } else if (j == 0) {
                if (i == r - 1) {
                    if (x[i][j] == x[r-1][1]) uf.unionSet(location(i, j, c), location(r-1, 1, c));
                    if (x[i][j] == x[r-2][0]) uf.unionSet(location(i, j, c), location(r-2, 0, c));                    
                } else {
                    if (x[i][j] == x[i-1][0]) uf.unionSet(location(i, j, c), location(i-1, 0, c));
                    if (x[i][j] == x[i+1][0]) uf.unionSet(location(i, j, c), location(i+1, 0, c));
                    if (x[i][j] == x[i][1]) uf.unionSet(location(i, j, c), location(i, 1, c));                    
                }
            } else if (i == r - 1) {
                if (j == c - 1) {
                    if (x[i][j] == x[r-1][c-2]) uf.unionSet(location(i, j, c), location(r-1, c-2, c));
                    if (x[i][j] == x[r-2][c-1]) uf.unionSet(location(i, j, c), location(r-2, c-1, c));                     
                } else {
                    if (x[i][j] == x[i][j-1]) uf.unionSet(location(i, j, c), location(i, j-1, c));
                    if (x[i][j] == x[i][j+1]) uf.unionSet(location(i, j, c), location(i, j+1, c));
                    if (x[i][j] == x[i-1][j]) uf.unionSet(location(i, j, c), location(i-1, j, c));  
                }
            } else if (j == c - 1) {
                    if (x[i][j] == x[i-1][j]) uf.unionSet(location(i, j, c), location(i-1, j, c));
                    if (x[i][j] == x[i+1][j]) uf.unionSet(location(i, j, c), location(i+1, j, c));
                    if (x[i][j] == x[i][j-1]) uf.unionSet(location(i, j, c), location(i, j-1, c)); 
            }
        }
    }

    // Now, I will assume each location (row, col) as a number following this fomula: (row - 1) * c + col 
    long n; cin >> n;
    long r1, c1, r2, c2;
    for (long i = 0; i < n; i++) {
        cin >> r1 >> c1 >> r2 >> c2; r1--; r2--; c1--; c2--;
        long location1 = location(r1, c1, c);
        long location2 = location(r2, c2, c);
        if (uf.isSameSet(location1, location2)) {
            if (x[r1][c1] == '0') cout << "binary\n";
            else if (x[r1][c1] == '1') cout << "decimal\n";
        } else {
            cout << "neither\n";
        }
    }
    
    return 0;
}