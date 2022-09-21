#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std; 

class Worker {
public:
    long initial;
    long increase;

    Worker(long ini, long inc) {
        initial = ini;
        increase = inc;
    }
}; 

bool sortWorkermin(const Worker &a, const Worker &b) {
    return a.initial + a.increase > b.initial + b.increase;
}

bool sortWorkermax(const Worker &a, const Worker &b) {
    return a.initial > b.initial;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long tasksN, workersN;
    vector<Worker> wkVec;
    cin >> tasksN >> workersN;
    for (long i = 0; i < workersN; i++) {
        long initial, increase;
        cin >> initial >> increase;
        Worker wk(initial, increase);
        wkVec.push_back(wk);
    }
    make_heap(wkVec.begin(), wkVec.end(), sortWorkermin);

    for (long i = 0; i < tasksN; i++) {
        Worker wk = wkVec[0];
        pop_heap(wkVec.begin(), wkVec.end(), sortWorkermin);
        wk.initial += wk.increase;
        wkVec[workersN - 1] = wk;
        push_heap(wkVec.begin(), wkVec.end(), sortWorkermin);
    }

    sort(wkVec.begin(), wkVec.end(), sortWorkermax);


    cout << wkVec[0].initial;

    return 0;
}