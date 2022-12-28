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
#include <map>
#include <set>

#define LEFT      'L'
#define RIGHT     'R'
#define BACKSPACE 'B'

using namespace std; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string keystrokes;
    list<char> input;
    getline(cin, keystrokes);
    auto cursor = input.begin();
    long len = keystrokes.length();
    for (long i = 0; i < len; i++) {
        if (keystrokes[i] == LEFT) {
            if (cursor != input.begin()) {
                cursor--;
            }
        } else if (keystrokes[i] == RIGHT) {
            if (cursor != input.end()) {
                cursor++;
            }
        } else if (keystrokes[i] == BACKSPACE) {
            if (!input.empty() && cursor != input.begin()) {
                auto temp = cursor;
                input.erase(--temp);
            }
        } else {
            input.insert(cursor, keystrokes[i]);
        }
    }
    for (auto &c: input) {
        cout << c;
    }
    return 0;
}