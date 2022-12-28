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

struct compare { 
   bool operator()(const string& l, const string & r)  
   {  
       return l > r;  
   }  
 };  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    long n;
    do {
        cin >> n;
        getline(cin, str);
    //while (cin >> n && n != 0) {
        map<string, priority_queue<string, vector<string>, compare>> map;
        for (long j = 0; j < n; j++) {
            string name;
            getline(cin, str);
            vector<string> v = split(str, " ");
            name = v[0];
            for (long i = 1; i < v.size(); i++) {
                auto find = map.find(v[i]);
                if (find != map.end()) {
                    find->second.push(name);
                } else {
                    priority_queue<string, vector<string>, compare> pq;
                    pq.push(name);
                    map[v[i]] = pq;
                }
            }
        }
        for (auto &food: map) {
            cout << food.first << ' ';
            while (!food.second.empty()) {
                cout << food.second.top() << ' ';
                food.second.pop();
            }
            cout << '\n';
        }
        cout << '\n';
    } while (n != 0) ;

    return 0;
}