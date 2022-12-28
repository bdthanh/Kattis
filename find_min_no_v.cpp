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
#include <climits>

using namespace std;
long find(long n) {
    if (n == 0) {
        return 1;
    } else if (n==1) {
        return 2;
    } 
    return find(n-1) + find(n-2) +1;
}
int main() {
    long n; cin >> n; 
    cout << find(n);
}