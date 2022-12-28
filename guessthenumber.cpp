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

using namespace std; 
 
int main() {
    long min = 1;
    long max = 1000; 
    long guessNum = (min + max)/2;
    string guess;
    for (long i = 0; i < 9; i++) {
      cout << guessNum << '\n';
      cin >> guess;
      if (guess == "lower") {
        max = guessNum;
        guessNum = (min + max)/2;
      } else if (guess == "higher") {
        min = guessNum;
        guessNum = (min + max)/2;
      } else {
        return 0;
      }
    }
    return 0;
}