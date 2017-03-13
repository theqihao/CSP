#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define INF 0x3fffffff
#define N 1005

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct POINT {
    int x, y;
};

struct CLIENT {
    int x, y;
    int num;
};

struct Node {
    int step;
    int x, y;
    Node(int _step, int _x, int _y) {
        step = _step;
        x = _x;
        y = _y;
    }
    bool operator < (const Node b) const {
        return step > b.step;
    }
};

int n, m, k, d;
int G[N][N];
bool vis[N][N];
CLIENT clients[N][N];

bool C(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

int main() {
   // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &d);

    priority_queue<Node> q;
    memset(vis, 0, sizeof(vis));
    memset(G, 0, sizeof(G));
    memset(clients, 0, sizeof(clients));

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        q.push(Node(0, x, y));
        vis[x][y] = 1;
    }
    for (int i = 0; i < k; i++) {
        int x, y, num;
        scanf("%d%d%d", &x, &y, &num);
        clients[x][y].num += num;
        G[x][y] = 1;
    }

    for (int i = 0; i < d; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x][y] = -1;
    }

    long long ans = 0;
    while (q.size()) {
        Node now = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (!C(nx, ny)) continue;
            if (vis[nx][ny] == 0 && G[nx][ny] != -1) {
                if (G[nx][ny] == 1) ans += clients[nx][ny].num * (now.step+1);
                q.push(Node(now.step+1, nx, ny));
                vis[nx][ny] = 1;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
