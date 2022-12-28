#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef unsigned long ulong;

void merge(ulong A[],long low, long mid, long high) {
    long N = high - low +1;
    ulong b[N];
    long left = low, right = mid + 1, bID = 0;
    while (left <= mid && right <= high) {
        b[bID++] = (A[left] <= A[right]) ? A[left++] :A[right++];
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

void mergeSort(ulong A[], long low, long high) {
    if (low < high) {
        long mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    long n, t; cin >> n >> t;
    ulong *A = (ulong*) malloc(n*sizeof(ulong)); 
    for (long i = 0; i < n; i++) {
        cin >> A[i]; 
    }
    mergeSort(A, 0, n-1);

    if (t == 1) {
        for (long i = 0, j = n - 1; i != j;) {
            if (A[i] + A[j] == 7777) {
                cout << "Yes";
                return 0;
                break;
            } else if (A[i] + A[j] < 7777) {
                i++;
            } else if (A[i] + A[j] > 7777) {
                j--;
            }
        } 
        cout << "No";
    } else if (t == 2) {
        bool isUnique = true;
        for (long i = 0; i < n - 1; i++) {
            if (A[i] == A[i + 1]) {
                isUnique = false;
                break;
            }
        } 
        if (isUnique) {
            cout << "Unique";
        } else {
            cout << "Contains duplicate";
        }
    } else if (t == 3) {
        long max = 1, maxNo = A[0], cur = A[0], count = 1;
        for (long i = 1; i < n; i++) {
            if (A[i] == cur) {
                count += 1;
            } else {
                if (count > max) {
                    max = count;
                    maxNo = A[i - 1];
                }
                count = 1;
                cur = A[i];
            }
        }
        if (max > n/2) {
            cout << maxNo;
        } else {
            cout << -1;
        }
    } else if (t == 4) {
        if (n%2==1) {
            cout << A[n/2];
        } else {
            cout << A[n/2-1] << ' ' << A[n/2];
        }
    } else if (t == 5) {

        for (long i = 0; i < n; i ++) {
            if (A[i] >= 100 && A[i] <= 999) {
                cout << A[i] << " ";
            }
        }
    }

    
    return 0;
}