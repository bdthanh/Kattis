#include <iostream>
#include <cmath>
#include <numeric>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    long n; std::cin >> n; 
    long ans = 0;
    long min = INT_MAX;
    for (long i = 0; i < n; i++) {
        long a; std::cin >> a;
        ans += a;
        if (min > a) min = a;
    }
    ans += (n-2)*min;
    std::cout << ans; 
    return 0;
}