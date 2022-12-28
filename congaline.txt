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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, q; cin >> n >> q;
    
    unordered_map<string, string> mapPartner;
    unordered_map<string, list<string>::iterator> mapPos;
    list<string> line;

    for (long i=0; i< n; i++) {
        string a, b; cin >> a >> b;
        mapPartner[a] = b;
        mapPartner[b] = a;
        line.push_back(a);
        auto it = --(line.end());
        mapPos[a] = it;
        line.push_back(b);
        it = --(line.end());
        mapPos[b] = it;
    }
    auto activeMic  = line.begin();
    for (long i = 0; i < q; i++) {
        char cmd; cin >> cmd; 
        if (cmd == 'F') {
            activeMic--;
        } else if (cmd == 'B') {
            activeMic++;
        } else if (cmd == 'R') {
            auto end = line.end(); end--;
            if (activeMic != end) {
                auto temp = activeMic;
                string name = *temp;
                activeMic++;
                line.erase(temp);
                line.push_back(name);
                mapPos[name] = --line.end();
            } else { //mic holder is at the end of the line
                activeMic = line.begin();
            }
        } else if (cmd == 'C') {
            auto end = line.end(); end--;
            if (activeMic != end) {
                auto temp = activeMic;
                string name = *temp;
                activeMic++;
                line.erase(temp);
                auto findPartner = mapPartner.find(name); 
                string partner = findPartner->second;
                auto findPartnerPos = mapPos.find(partner); 
                auto partnerPos = findPartnerPos->second;
                line.insert(++partnerPos, name);
                mapPos[name] = --partnerPos;
            } else { //mic holder is at the end of the line
                activeMic = line.begin();
            }
        } else if (cmd == 'P') {
            auto it = mapPartner.find((*activeMic));
            cout << it->second << '\n';
        }
    }

    cout << '\n';
    for (auto i = line.begin(); i != line.end(); i++) {
        cout << (*i) << '\n';
    }
    
    return 0;
}