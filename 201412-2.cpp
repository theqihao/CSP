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

int n;
int a[505][505];

enum {RIGHT, DOWN_LEFT, DOWN, UP_RIGHT};

int main() {
    //freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n ;i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int status = DOWN_LEFT;
    int old_status = RIGHT;
    int x = 0;
    int y = 0;
    int sum = n*n-1;
    printf("%d ", a[x][y]);
    y++;
    while (sum--) {
        printf("%d ", a[x][y]);
        switch (status) {
        case RIGHT:
            //printf("RIGHT\n");
            if (old_status == UP_RIGHT) {
                y--;
                x++;
                status = DOWN_LEFT;
            } else if (old_status == DOWN_LEFT) {
                x--;
                y++;
                status = UP_RIGHT;
            }
            old_status = RIGHT;
            break;
        case DOWN:
            //printf("DOWN\n");
            if (old_status == UP_RIGHT) {
                x++;
                y--;
                status = DOWN_LEFT;
            } else if (old_status == DOWN_LEFT) {
                x--;
                y++;
                status = UP_RIGHT;
            }
            old_status = DOWN;
            break;
        case DOWN_LEFT:
            //printf("DOWN_LEFT\n");
            if (x+1 <= n-1 && 0 <= y-1) {
                status = DOWN_LEFT;
                x++;
                y--;
            } else if (x+1 <= n-1) {
                status = DOWN;
                x++;
            } else {
                status = RIGHT;
                y++;
            }
            old_status = DOWN_LEFT;
            break;
        case UP_RIGHT:
            //printf("UP_RIGHT\n");
            if (0 <= x-1 && y+1 <= n-1) {
                status = UP_RIGHT;
                x--;
                y++;
            } else if (y+1 <= n-1) {
                status = RIGHT;
                y++;
            } else {
                status = DOWN;
                x++;
            }
            old_status = UP_RIGHT;
            break;
        }

    }
    return 0;
}
