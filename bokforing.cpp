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
    long peopleNum, n, id ,wealth; 
    string cmd;
    cin >> peopleNum >> n;
    unordered_map<long, long> umapIDwithWealth;
    //unordered_map<long, bool> umapIDwithStatus;
    unordered_set<long> resetID;
    bool isSetagain = false, isRestart = false; 
    long restartVal;
    for (long i = 1; i <= peopleNum; i++) {
        umapIDwithWealth[i] = 0; 
    }
    for (long i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "SET") {
            cin >> id >> wealth;
            umapIDwithWealth[id] = wealth;
            //umapIDwithStatus[id] = true;
            resetID.insert(id);
        } else if (cmd == "RESTART") {
            cin >> restartVal;
            isRestart = true;
            //umapIDwithStatus.clear();
            resetID.clear();
        } else { //cmd == "PRINT"
            cin >> id;
            //auto its = umapIDwithStatus.find(id);
            auto its = resetID.find(id);
            auto itw = umapIDwithWealth.find(id);
            if (its != resetID.end() || !isRestart) {
                cout << itw->second << '\n';
            } else  {
                cout << restartVal << '\n';
            }
        }
    }
    return 0;
}