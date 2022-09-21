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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    unordered_map<string, long> mapVarwithVal;
    unordered_map<long, string> mapValwithVar;
    while (1){
        string cmd;
        cin >> cmd;
        if (cmd == "def") {
            string var; cin >> var;
            long val; cin >> val;
            mapVarwithVal[var] = val;
            mapValwithVar[val] = var;
        } else if (cmd == "calc") {
            string inputCal;
            getline(cin, inputCal);
            string out = inputCal.substr(1, inputCal.length() - 1);
            cout << out << ' ';
            vector<string> v = split(inputCal, " ");
            // for (long i = 0; i <v.size(); i++) {
            //     cout << v[i] << ' ';
            // } cout << '\n';
            long ans = 0;
            for (long i = 0; i < v.size(); i++) {
                if (v[i] == "-") {
                    i++;
                    auto it = mapVarwithVal.find(v[i]);
                    if (it == mapVarwithVal.end()) {
                        cout << "unknown\n";
                        break;
                    } else {
                        ans -= it->second;
                    }
                } else if (v[i] == "+") {
                    i++;
                    auto it = mapVarwithVal.find(v[i]);
                    cout << it->second << ' ';
                    if (it == mapVarwithVal.end()) {
                        cout << "unknown\n";
                        cout << ans;
                        break;
                    } else {
                        ans += it->second;
                    }
                } else if (v[i] == "=") {
                    auto it = mapValwithVar.find(ans);
                    if (it == mapValwithVar.end()) {
                        cout << "unknown\n";
                        break;
                    } else {
                        cout << it->second << '\n';
                        break;
                    }
                } else {   //v[i] is name of variable
                    auto it = mapVarwithVal.find(v[i]);
                    if (it == mapVarwithVal.end()) {
                        cout << "unknown\n";
                        break;
                    } else {
                        ans += it->second;
                    }
                }
            }
        } else if (cmd == "clear") {
            mapVarwithVal.clear();
            mapValwithVar.clear();
        }
    }
    
    return 0;
}