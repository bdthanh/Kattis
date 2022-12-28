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
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin >> n;
  int layer = 0;
  unordered_map<int, unordered_map<string, string>> umap;
  unordered_map<string, string> blockMap; 
  umap[layer] = blockMap; 
  for (int i = 0; i < n; i++) {
    string cmd; cin >> cmd;
    if (cmd == "TYPEOF") {
      string var; cin >> var;
      auto it = umap[layer].find(var);
      bool isFound = false;
      for (int j = layer; j >= 0; j--) {
        auto it = umap[j].find(var);
        if (it != umap[j].end()) {
          cout << it->second << "\n";
          isFound = true;
          break;
        } 
      }
      if (!isFound) {
        cout << "UNDECLARED\n";
      }
    } else if (cmd == "DECLARE") {
      string var, type; cin >> var >> type;
      auto it = umap[layer].find(var);
      if (it != umap[layer].end()) {
        cout << "MULTIPLE DECLARATION\n";
        return 0;
      } else {
        umap[layer].insert({var, type});
      }
    } else if (cmd == "{") {
      unordered_map<string, string> tempBlockMap; 
      layer++;
      umap[layer] = tempBlockMap; 
    } else if (cmd == "}") {
      umap.erase(umap.find(layer));
      layer--;
    }
  }
}