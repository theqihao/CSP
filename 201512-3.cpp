#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

#define row 0
#define ver 1

using namespace std;

char g[105][105];
char fan[2];

bool vis[105][105];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
int p;

// 0 1 0 2 0
void line(int x1, int y1, int x2, int y2) {
    int op;
    if (x1 == x2) op = 1;
    else op = 0;

    char c = op == 1 ? '|' : '-';
    if (op) {
        for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                if (g[y][x1] == '+') continue;
            if (fan[op] == g[y][x1]) {
                g[y][x1] = '+';
            } else {
                g[y][x1] = c;
            }
        }
    } else {
        y1 = m - 1 - y1;
        for (int x = min(x1,x2); x <= max(x1, x2); x++) {
            if (g[y1][x] == '+') continue;
            if (fan[op] == g[y1][x]) {
                g[y1][x] = '+';
            } else {
                g[y1][x] = c;
            }
        }
    }
}

int flag = 0;

void next(int x, int y, char c) {
    if (g[x][y] == '-' || g[x][y] == '|' || g[x][y] == '+' || vis[x][y] == 1) {
        return ;
    }
    vis[x][y] = 1;
    g[x][y] = c;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < m && 0 <= ny && ny < n)
            next(nx, ny, c);
    }
}


int main() {
  //  freopen("in.txt", "r", stdin);
    fan[0] = '|';
    fan[1] = '-';
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }

    int op;
    for (int i = 0; i < p; i++) {
        scanf("%d", &op);
        if (op == 0) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            line(x1, y1, x2, y2);
        } else if (op == 1) {
            int x1, y1;
            char c;
            scanf("%d%d", &x1, &y1);
            cin >> c;
            memset(vis, 0 , sizeof(vis));
            next(m - 1 - y1, x1, c);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}
