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

int a[30][6];
int v[30][6];

void print(int num, int x) {
    int flag = 0;
    for (int i = 0; i < num; i++) {
        if (flag == 0) {
            flag = 1;
            printf("%d", x++);
        } else {
            printf(" %d", x++);
        }
    }
    printf("\n");
}

void slove(int x) {
    int flag = 0;
    for (int i = 0; i < 20; i++) {
        if (a[i][5] >= x) {
            print(x, a[i][5-a[i][5]]);
            a[i][5] -= x;
            flag = 1;
            break;
        }
    }
    if (flag) {
        return ;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 5; j++) {
            while (a[i][5] > 0 && x > 0) {
                if (flag == 0) {
                    flag = 1;
                    printf("%d", a[i][5-a[i][5]]);
                } else {
                    printf(" %d", a[i][5-a[i][5]]);
                }
                x--;
                a[i][5]--;
            }
            if (x <= 0) {
                break;
            }
        }
        if (x <= 0) {
            break;
        }
    }
    printf("\n");
}

int main() {
    //freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(0));
    int x = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = x++;
        }
        a[i][5] = 5;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        slove(x);
    }
    return 0;
}
