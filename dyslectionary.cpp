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

using namespace std; 

void sort_and_print(vector<string> &v, unordered_map<string, string> &m, long maxLen) {
    sort(v.begin(), v.end());
    for (long i = 0; i < v.size(); i++) {
        auto find = m.find(v[i]);
        for (long j = 0; j < maxLen - v[i].length(); j++) {
            cout << " ";
        }
        cout << find->second << '\n' ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    vector<string> v;
    unordered_map<string, string> m;
    long maxLen = 0, count = 0;
    while (getline(cin, str)) {
        if(str != "") {
            long len = str.length();
            maxLen = max(maxLen, len);
            string temp = str;
            reverse(str.begin(), str.end());
            m[str] = temp;
            v.push_back(str);
        } else { // str == "" --> new group
            sort_and_print(v, m, maxLen);
            cout << '\n';
            v.clear();
            maxLen = 0;
        }
    }
    sort_and_print(v, m, maxLen);

    return 0;
}