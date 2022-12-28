#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <stack>
#include <cassert>
#include <unordered_map>

using namespace std; 
//typedef long long ll;

void radixSortDiffBase(vector<long> &v, long n, long max ){
// instead of using normal radix sort of base 10, i am using base = 1024
    //long base = 1024;
    vector<queue<long>> digits(1024, queue<long>());
    long maxSizeinNewBase = (long)(log(max)/log(1024)) + 1; // finding the size of max number in new base --> max size 

    for (long i = 0; i < maxSizeinNewBase; i++){

        long factor = pow(1024,i);
        for (long j = 0; j < n; j++){
            digits[(v[j]/factor)%1024].push(v[j]);
        }
        long j = 0;
        for (long k = 0 ; k < 1024; k++){
            while (!digits[k].empty()){
                v[j] = digits[k].front();
                digits[k].pop();
                j++;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long tc, n, a, b, c, x, y;
    cin >> tc;
    long max = -1;
    for (long i = 0; i < tc; i++) {
        vector<long> s;
        cin >> n >> a >> b >> c >> x >> y;
        s.push_back(a);
        if (a > max) {
            max = a; 
        }
        for (long j = 1; j < n; j++) {
            long x = (s[j - 1] * 1ll * b + a) % c;
            s.push_back(x);
            if (x > max) {
                max = x; 
            }
        }
        radixSortDiffBase(s, n, max);
        long v = 0;
        for (long k = 0; k < n; k++) {
            v = (v *1ll * x + s[k]) % y;
        }
        cout << v << '\n';
    }

    return 0;
}