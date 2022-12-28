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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<list<string>> listString; 
    long n; cin >> n;
    string str;
    for (long i = 0; i < n; i++) {
        cin >> str;
        list<string> input;
        input.push_back(str);
        listString.push_back(input);
    }
    long first, second;
    for (long i = 0; i < n - 1; i++) {
        cin >> first >> second; 
        first--; second--;
        listString[first].splice(listString[first].end(), listString[second]);
    }
    for (auto &x: listString) {
        if (!x.empty()) {
            for (auto &word: x) {
                cout << word;
            }
            cout << '\n';
        }
    }

    return 0;
}