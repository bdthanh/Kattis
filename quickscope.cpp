/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

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
    long n; cin >> n;
    long blockNum = 0;
    unordered_map<string, string> m;
    vector<unordered_map<string,string>> block;
    unordered_map<string, vector<long>> mapVarwithWhereItIs; //to map the variable with the code block that it belongs to 
    block.push_back(m);

    for (long i  = 0; i < n; i++) {
        string cmd; cin >> cmd;
        if (cmd == "{") {
            unordered_map<string, string> tempM;
            block.push_back(tempM);
            blockNum ++;
        } else if (cmd == "}") {
            //when closing a block, I need to erase all variables in that block.
            for (auto &v: block.back()) {
                auto it = mapVarwithWhereItIs.find(v.first);
                it->second.pop_back();
            }
            block.pop_back();
            blockNum --;
        } else if (cmd == "DECLARE") {
            string var; cin >> var; 
            string type; cin >> type;
            // when declaring a vaiable, check if it exists or not
            // if no, map it 
            // if yes, push the new block into the var places array
            auto it = mapVarwithWhereItIs.find(var);
                mapVarwithWhereItIs[var].push_back(blockNum);
            auto findVar = block.back().find(var);
            if (findVar == block.back().end()) {
                block.back()[var] = type;
            } else {
                cout << "MULTIPLE DECLARATION\n";
                break;
            }
        } else if (cmd == "TYPEOF") {
            string var; cin >> var;
            auto findVar = mapVarwithWhereItIs.find(var);
            if (findVar == mapVarwithWhereItIs.end() || findVar->second.empty()) {
                cout << "UNDECLARED\n";
            } else {
                auto itV = block[findVar->second.back()].find(var);
                cout << itV->second << '\n';
            }
        }
    }
    
    return 0;
}