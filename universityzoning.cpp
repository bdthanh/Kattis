/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <numeric>
using namespace std;
long d = 0;
void merge(long A[], long low, long mid, long high) { 
    long N = high - low + 1; 
    long  b[N];
    long left = low, right = mid + 1, bID = 0;
    while (left <= mid && right <= high) {
        b[bID++] = (A[left] <= A[right]) ? A[left++] : A[right++]; 
    }
    while (left <= mid) {
        b[bID++] = A[left++];
    }
    while (right <= high) {
        b[bID++] = A[right++];
    }
    for (long k = 0; k < N; k++) {
        A[low + k] = b[k];
    }
}   

void mergeSort(long A[], long low, long high) {
    if (low < high) {
        long mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

class Cell {
public:
    long row;
    long col;

    Cell(long row, long col): row(row), col(col) {} 
};

bool sortCell(const Cell &a, const Cell &b) {
    if (a.row != b.row) {
        return a.row < b.row;
    }
    return a.col < b.col;
}

class Faculty {
public: 
    long k;
    vector<Cell> cell;
    long* stuSteps = (long*) malloc(2000 * sizeof(long));
    long count = 0; 
    long minTotalSteps;
    long minStu;

    Faculty() {
        cin >> k;
        for (long i = 0; i < k; i ++) {
            long a, b;
            cin >> a >> b;
            cell.push_back(Cell(a, b));
        }
        sort(cell.begin(), cell.end(), sortCell);
    };
};

class Student {
public:
    long initialR;
    long initialC;
    long stuNo;
    long facNo;
    //constructor
    Student(): initialR(0), initialC(0), stuNo(0), facNo(0) {}

};

bool fn(const Student &x, const Student &y) {
    return x.stuNo < y.stuNo;
}
 
int main() {
    long r, c, f, s, g, row, col;
    long long ans = 0;
    cin >> r >> c >> f >> s >> g;
    long* X = (long*) malloc(f*sizeof(long));
    if (X == NULL) {
        free(X);
        return 1;
    }
    for (long i = 0; i < f; i ++) {
        X[i] = 0;
    }
    Faculty** F = new Faculty*[f] ;
    for(long i = 0; i < f; i++) {
        F[i] = new Faculty;
    }

    vector<Student> v(s, Student());
    for (long i = 0; i < s; i++) {
        cin >> v[i].initialR >> v[i].initialC >> v[i].stuNo >> v[i].facNo;
    }
    sort(v.begin(), v.end(), fn);
    for (long i = 0; i < s; i++) {
        F[v[i].facNo - 1]->stuSteps[F[v[i].facNo - 1]->count] = (abs(v[i].initialR - F[v[i].facNo - 1]->cell[F[v[i].facNo - 1]->count].row) + abs(v[i].initialC - F[v[i].facNo - 1]->cell[F[v[i].facNo - 1]->count].col));
        F[v[i].facNo - 1]->count += 1;
    }
    for (long i = 0; i < f; i++) {
        cin >> F[i]->minStu; 
    }

    for (long i = 0; i < f; i++) {
        mergeSort(F[i]->stuSteps, 0, F[i]->count - 1);
        for (long j = 0; j < F[i]->minStu;j ++) {
            X[i] += F[i]->stuSteps[j];
        }
    }
    mergeSort(X, 0, f-1);
    for (long i = 0; i < g; i++) {
        ans += X[i];
    }
    cout << ans;    

    free(X);

    return 0;
}