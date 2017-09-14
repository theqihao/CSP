#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define INF 0x3fffffff
#define N 3500

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

typedef long long LL;
using namespace std;


int a[30][15];
int x[5][5];



int main() {
    //freopen("in.txt", "r", stdin);

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    int bt = 0;
    for (int i = 0; i < 4; i++) {
        int flag = 0;
        for (int j = 0; j < 4; j++) {
            if (x[i][j] == 1) {
                flag = 1;
            }
        }
        if (flag) {
            bt = i+1;
        }
    }
    int py;
    scanf("%d", &py);
    py--;
    int xia = 0;
    for (xia = 0; xia < 15-bt; xia++) {
        int flag = 0;
        for (int i = xia, ii = 0; ii < 4; i++, ii++) {
            for (int j = py, jj = 0; jj < 4; j++, jj++) {
                if (a[i][j] == 1 && x[ii][jj] == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 1) {
            xia--;
            break;
        }
    }
    for (int i = xia, ii = 0; ii < 4; i++, ii++) {
        for (int j = py, jj = 0; jj < 4; j++, jj++) {
            a[i][j] |= x[ii][jj];
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                printf("%d", a[i][j]);
            } else {
                printf(" %d", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
