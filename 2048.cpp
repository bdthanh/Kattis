#include <iostream>

using namespace std;

void print(long **grid) {
    for (long i = 0; i < 4; i ++) {
        for (long j = 0; j < 4; j ++ ) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

void moveL(long **grid){
    for (int i = 0; i < 4; i++) {
        long j = 0, cur = 0, next = 0, noPair = 0;
        while (j != 4-noPair) {
            if (grid[i][j] == 0) {
                j++;
            } else {
                //grid[i][j] !=0
                if (grid[i][cur] == 0) {
                    cur == j;
                    j ++;
                } else if (grid[i][cur] == grid[i][j]) {
                    grid[i][cur] *= 2;
                    next = cur + 1;
                    noPair += 1;
                } else {
                    //grid[i][cur] != grid[i][j]
                    cur == j;
                    next = j;
                    j++;
                }
            }
        }
        for (int k = 3; k >= 3 - noPair; k--) {
            grid[i][k] = 0;
        }
    }
}
int main() {
    //0: left 
    //1: up
    //2: right
    //3: down
    long **grid = (long**) malloc(4*sizeof(long*));
    for (int i = 0; i < 4; i++) {
        grid[i] = (long*) malloc(4*sizeof(long));
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }
    long move; cin >> move; 

    if (move == 0){
        //move left
    } else if (move == 1) {
        //move up
    } else if (move == 2) {
        //move right
    } else if (move == 3) {
        //move down
    }

    for (int i = 0; i < 4; i++) {
        free(grid[i]);
    } 
    free(grid);
    return 0;
}