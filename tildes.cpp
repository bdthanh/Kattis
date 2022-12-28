/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {                                // OOP style
private:
  vector<int> p, rank, setSize;                           // vi p is the key part
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

  int numDisjointSets() { 
       return numSets; }      // optional
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
    int guestsNum, queriesNum, personA, personB;
    char x;
    cin >> guestsNum >> queriesNum;
    UnionFind UF(guestsNum);
    for (int i = 0; i < queriesNum; i++) {
        cin >> x;
        if (x == 't') {
            cin >> personA >> personB;
            UF.unionSet(--personA, --personB);
        } else {
            cin >> personA;
            cout << UF.sizeOfSet(--personA) << '\n';
        }
    }
    return 0;
}