#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;


char G[55][55];
char rG[55][55];
int used[55][55];

int n, m;
int sx, sy;
int ex, ey;


void dfs(int x, int y) {
    if (G[x][y] == '#' || x < 0 || x >= n || y < 0 || y >= m || used[x][y] == 1) return ;
    used[x][y] = 1;
    if (G[x][y] == '+') {
        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
    } else if (G[x][y] == '|') {
        dfs(x+1, y);
        dfs(x-1, y);
    } else if (G[x][y] == '-') {
        dfs(x, y+1);
        dfs(x, y-1);
    } else if (G[x][y] == '.') {
        dfs(x+1, y);
    }
}

void dfs2(int x, int y) {
    if (rG[x][y] == '#' || x < 0 || x >= n || y < 0 || y >= m || used[x][y] == 2) return ;
    used[x][y] = 2;
    if (rG[x-1][y] == '+' || rG[x-1][y] == '|' || rG[x-1][y] == '.') {
        dfs2(x-1, y);
    }
    if (rG[x+1][y] == '|' || rG[x+1][y] == '+') {
        dfs2(x+1, y);
    }
    if (rG[x][y-1] == '-' || rG[x][y-1] == '+') {
        dfs2(x, y-1);
    }
    if (rG[x][y+1] == '-' || rG[x][y+1] == '+') {
        dfs2(x, y+1);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", G[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 'S') {
                sx = i;
                sy = j;
                G[i][j] = '+';
            }
            if (G[i][j] == 'T') {
                ex = i;
                ey = j;
                G[i][j] = '+';
            }
        }
    }
    memcpy(rG, G, sizeof(G));
    memset(used, 0, sizeof(used));
    dfs(sx, sy);
    if (used[ex][ey] == 0) {
        printf("I'm stuck!");
        return 0;
    }
    dfs2(ex, ey);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j] == 1) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
