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

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr(pos_start));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    set<string> s;
    while (getline(cin, str)) {
        vector<string> v = split(str, " ");
        for (auto &x: v) s.insert(x);
    }
    set<string> s2;
    auto it1 = s.begin();
    while (it1 != s.end()) {
        auto it2 = s.begin();
        while (it2 != s.end()) {
            if (it1 != it2) {
                string x = (*it1).append());
                s2.insert(x);
                //cout << *it1 << *it2 << '\n';
            }
            it2++;
        }
        it1++;
    }
    
    return 0;
}