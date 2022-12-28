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

class People{
public:
    string name;
    unsigned long cl;

    People(string _name, unsigned long _cl) {
        name = _name;
        cl = _cl;
    }
};

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
    bool operator()(const People &a, const People &b) {  
        if (a.cl != b.cl) return a.cl < b.cl;
        return a.name > b.name;  
    }  
 }; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long tc, n; string input;
    cin >> tc;
    priority_queue<People, vector<People>, compare> pq;
    for (long i= 0; i < tc; i++) {
        cin >> n;
        getline(cin, input);
        for (long j = 0; j < n; j++) {
            getline(cin, input);
            unsigned long cl = 0;
            // analyse input
            vector<string> vn = split(input, ": "); 
            string name = vn[0];
            vector<string> v = split(vn[1], " ");
            vector<string> vecClass = split(v[0], "-");
            for (long k = vecClass.size()-1; k >= 0; k--) {
                long x;
                if (vecClass[k] == "upper") x = 3;
                else if (vecClass[k] == "middle") x = 2;
                else if (vecClass[k] == "lower") x = 1;
                cl *= 10; cl += x;
            }
            while (cl < 1000000000) {
                cl *= 10; cl += 2;          
            }
            People p(name, cl);
            pq.push(p);
        }
        while (!pq.empty()) {
            cout << pq.top().name << '\n';
            pq.pop();
        }
        
        cout << "==============================\n";
    }

    return 0;
}