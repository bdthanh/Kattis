
/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <stack>
#include <climits>
#include <vector> 
using namespace std;

long getMin(vector<long> &input, long lo, long hi) {
    long min = input[lo];
    for (long i = lo; i <= hi; i++) {
        if (min > input[i]) {
            min = input[i];
        }
    }
    return min; 
}

int main() {
    long n, height; cin >> n;
    long curBase = INT_MAX;
    long curMaxHeightID = -1;
    long maxJump = -1;
    vector<long> input;
    stack<long> peakMountainID;
    stack<long> base;
    //stack<long> id;
    for (long i = 0; i < n; i++) {
        cin >> height;
        input.push_back(height);
    } 
    for (long i = 0; i < n; i++) {
        if (peakMountainID.empty()) {
            peakMountainID.push(i);
            base.push(curBase);
            curMaxHeightID = i;
        } else if (!peakMountainID.empty()) {
            //while (!peakMountain.empty()) {
            if (input[curMaxHeightID] < input[i]) { //pop til empty then push
                curBase = getMin(input, peakMountainID.top(), i);
                while (!peakMountainID.empty()) {
                    if (peakMountainID.top() != curMaxHeightID){
                        curBase = min(curBase, base.top());
                        //cout << curBase << " ";
                    }
                    //maxJump = max(maxJump, ); 
                    peakMountainID.pop();
                    base.pop();
                        
                }
                //long newBase = getMin(input, peakMountainID.top(), i);
                maxJump = max(maxJump, input[curMaxHeightID] - curBase);
                //cout << curBase;
                curMaxHeightID = i;
                peakMountainID.push(i);
                base.push(INT_MAX); //to prevent finding the maxfall of this
                curBase = INT_MAX;
            } else if (input[curMaxHeightID] > input[i]) { //pop til top is taller or equal
                //long aftID = i;
                curBase = getMin(input, peakMountainID.top(), i);
                //cout << curBase << " ";
                while (input[peakMountainID.top()] <= input[i]) {
                    curBase = min(base.top(), curBase);
                    //cout << curBase << " ";
                    //aftID = peakMountainID.top();
                    peakMountainID.pop(); //pop until top is taller or equal
                    base.pop();
                }
                maxJump = max(maxJump, input[i] - curBase);
                peakMountainID.push(i);
                base.push(curBase);
            } else if (input[curMaxHeightID] == input[i]) {
                curBase = getMin(input, peakMountainID.top(), i);
                while (peakMountainID.top() != curMaxHeightID) {
                    curBase = min(curBase, base.top());
                    peakMountainID.pop();
                    base.pop();
                }
                maxJump = max(maxJump, input[i] - curBase);
                curMaxHeightID = i;
                peakMountainID.push(i);
                //curBase = INT_MAX;
                base.push(curBase);
                
            }
            //} 

        }
    }
    //the remaining stack contains some peakMountain in descending order
    // while (base.top() != INT_MAX) {
    while (!peakMountainID.empty()) {
        //if (base.top() != INT_MAX) {
            //cout << input[peakMountainID.top()] << " " << base.top();
            maxJump = max(maxJump, input[peakMountainID.top()] - base.top());
            peakMountainID.pop();
            base.pop();
        //}
    }

    if (maxJump < 0) {
        cout << 0 << endl;
    } else {
        cout << maxJump << endl;
    }
}