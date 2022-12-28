/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
#define HOME      '['
#define END       ']'
#define BACKSPACE '<'
#define NOTHING   '0'

int main() {
    long num; cin >> num;
    for (long k = 0; k <= num; ++k) {
        string type;
        list<char> output;
        getline(cin, type);
        if (k != 0) {
            long lenType = type.length();
            auto cursor = output.begin();
            for (long i = 0; i < lenType; i++) {
                if (type[i] == BACKSPACE) {
                    if (output.size() != 0 && cursor != output.begin()) {
                        auto tempCursor = cursor;
                        output.erase(--tempCursor);
                    }
                } else if (type[i] == HOME) {
                    cursor = output.begin();
                } else if (type[i] == END) {
                    cursor = output.end();
                } else { 
                    output.insert(cursor, type[i]);
                }
            }
            for (auto n: output) {
                cout << n;
            }
            cout << endl;
        }
    }
    return 0;
}