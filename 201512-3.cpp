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

char a[120][120];
int n, m, q;

bool check(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m) {
        return true;
    } else {
        return false;
    }
}

bool is_ok(int x, int y) {
    if (a[x][y] != '|' && a[x][y] != '-' && a[x][y] != '+') {
        return true;
    } else {
        return false;
    }
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void draw_line() {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
    x1 = n-1-x1;
    x2 = n-1-x2;
    if (x1 == x2) {
        char c = '-';
        if (y2 < y1) {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (int i = y1; i <= y2; i++) {
            if (a[x1][i] == '|' || a[x1][i] == '+') {
                a[x1][i] = '+';
            } else {
                a[x1][i] = c;
            }
        }
    } else {
        char c = '|';
        if (x2 < x1) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        for (int i = x1; i <= x2; i++) {
            if (a[i][y1] == '-' || a[i][y1] == '+') {
                a[i][y1] = '+';
            } else {
                a[i][y1] = c;
            }
        }
    }
}

int xs[10001];
int ys[10001];

void fill_a() {
    int x, y;
    char c;
    scanf("%d%d %c", &y, &x, &c);
    x = n-1-x;
    //printf("%c\n", c);
    getchar();
    int index = 0;
    a[x][y] = c;
    xs[index] = x;
    ys[index] = y;
    index++;
    while (index) {
        int cx = xs[index-1];
        int cy = ys[index-1];
        index--;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (check(nx, ny) && is_ok(nx, ny) && a[nx][ny] != c) {
                a[nx][ny] = c;
                xs[index] = nx;
                ys[index] = ny;
                index++;
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);

    scanf("%d%d%d", &m, &n, &q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '.';
        }
    }

    int op;
    for (int i = 0; i < q; i++) {
        scanf("%d", &op);
        if (op == 0) {
            draw_line();
        } else {
            fill_a();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
