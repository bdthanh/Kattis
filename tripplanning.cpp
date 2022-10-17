/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long cityNum, trainNum; cin >> cityNum >> trainNum;
    long trains[cityNum+1] = {0};

    if (cityNum!= 2) {
        for (long i = 1; i <= trainNum; i++) {
            long cityA, cityB; cin >> cityA >> cityB;
            long from = min(cityA, cityB);
            long to = max(cityA, cityB);
            if (from < cityNum && from == to-1) {
                trains[from] = i;
            } else if (from == 1 && to == cityNum) {
                trains[to] = i;
            } if (cityNum == 2 && from == 1 && to == 2) {
                trains[1] = i; trains[2] = i;
                break;
            }
        }
    } else { // cityNum = 2. I divide into 2 cases to avoid redundant check 
        for (long i = 1; i <= trainNum; i++) {
            long cityA, cityB; cin >> cityA >> cityB;
            long from = min(cityA, cityB);
            long to = max(cityA, cityB);
            if (from == 1 && to == 2) {
                trains[1] = i; trains[2] = i;
                break;
            }
        }
    }
    bool canContinue = false;
    for (long i = 1; i <= cityNum; i++) {
        if (trains[i] != 0) {
            canContinue = true;
        } else {
            canContinue = false;
            break;
        }
    }
    if (canContinue) {
        for (long i = 1; i <= cityNum; i++) cout << trains[i] << '\n';
    } else {
        cout << "impossible\n";
    }
    
    return 0;
}