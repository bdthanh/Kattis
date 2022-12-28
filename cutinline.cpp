#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

int main() {
    long n; cin >> n;
    list<string> queue; 
    for (long i =0; i < n; i++) {
        string name; cin >> name;
        queue.push_back(name);
    }
    long c; cin >> c;
    for (long i = 0; i < c; i++) {
        string cmd; cin >> cmd;
        if (cmd == "cut") {
            string a, b; cin >> a >> b;
            auto ita = find(queue.begin(), queue.end(), a);
            auto itb = find(queue.begin(), queue.end(), b);
            if (ita == queue.end()) {
                queue.insert(itb, a);
            } else {
                queue.remove(a);
                queue.insert(itb, a);
            }
        } else if (cmd == "leave") {
            string name; cin >> name;
            auto it = find(queue.begin(), queue.end(), name);
            queue.erase(it);
        }
    }
    for (auto k = queue.begin(); k!= queue.end(); k++) {
        cout << *k << '\n';
    }
}