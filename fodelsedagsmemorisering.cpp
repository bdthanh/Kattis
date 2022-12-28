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

class Friend {
public:
    string name;
    long likes;

    Friend(string _name, long _likes) {
        likes = _likes;
        name = _name;
    }

    // bool operator==(const Friend& p) const
    // {
    //     return name == p.name && likes == p.likes;
    // }
    
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, pair<string, long>> map;
    pair<string, long> pairNamewLike;
    string name, birthday; 
    long like, n; cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> name >> like >> birthday;
        pairNamewLike.first = name;
        pairNamewLike.second = like;
        //Friend fr(name, like);
        auto find = map.find(birthday);
        if (find == map.end()) {
            map[birthday] = pairNamewLike;
        } else {
            if (find->second.second < like) {
                find->second = pairNamewLike;
            }
        }    
    }
    vector<string> rememberedName;
    for (auto &x: map) {
        rememberedName.push_back(x.second.first);
    }

    sort(rememberedName.begin(), rememberedName.end());
    cout << rememberedName.size() << '\n';
    for (auto &x: rememberedName) {
        cout << x << '\n';
    }

    return 0;
}