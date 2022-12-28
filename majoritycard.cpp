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

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n; cin >> n;
  unordered_map<int, int> ma;
  list<pair<int, int>> li; 
  for (int i = 0; i < n; i++) {
    int tempNumber = -1, tempValue = -1;
    string cmd; cin >> cmd; 
    if (cmd == "PUT_TOP") {
      int x, y; cin >> x >> y;
      li.push_front(make_pair(y,x));
      ma[y] += x;
    } else if (cmd == "PUT_BOTTOM") {
      int x, y; cin >> x >> y;
      li.push_back(make_pair(y,x));
      ma[y] += x;
    } else if (cmd == "REMOVE_TOP") {
      int z; cin >> z;
      while (z > 0) {
        auto cur = li.front().second;
        if (z >= cur) {
          ma[li.front().first] -= cur;
          z -= cur;
          li.pop_front();
        } else {
          ma[li.front().first] -= z;
          li.front().second -= z;
          z = 0;
        }
      }
    } else if (cmd == "REMOVE_BOTTOM") {
      int z; cin >> z;
      while (z > 0) {
        auto cur = li.back().second;
        if (z >= cur) {
          ma[li.back().first] -= cur;
          z -= cur;
          li.pop_back();
        } else {
          ma[li.back().first] -= z;
          li.back().second -= z;
          z = 0;
        }
      }
    }
    for (auto &it: ma) {
      if (it.second > tempNumber) {
        //cout << it.second << tempNumber << '\n';
        tempNumber = it.second;
        tempValue = it.first;
      } else if (it.second == tempNumber) {
        if (it.first < tempValue) {
          tempValue = it.first;
        }
      }
    }
    cout << tempValue << '\n';
  }
}

