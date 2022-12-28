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

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, num, sum = 0; cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> num;
        long a, b;
        a = num/10;
        b = num%10;
        sum += (int) pow(a, b);
    }
    cout << sum;

    return 0;
}