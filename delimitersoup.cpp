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

using namespace std; 

bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClose(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool isMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    stack<char> st;
    long n; cin >> n;
    getline(cin, str);
    getline(cin, str);
    for (long i = 0; i < n; i++) {
        if (isOpen(str[i])) {
            st.push(str[i]);
        } if (isClose(str[i])) {
            if (st.empty()) {
                cout << str[i] << ' ' << i;
                return 0;
            } else if (isMatch(st.top(), str[i])) {
                st.pop();
            } else {
                cout << str[i] << ' ' << i;
                return 0;
            }
        }
    }
    cout << "ok so far";

    return 0;
}