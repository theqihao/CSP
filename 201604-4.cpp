#include <istream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct WEI {
    int l, r;
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

int n, m, r;
int G[105][105];
bool vis[105][105][10005];
WEI wei[105][105];

bool C(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= m;
}

bool W(int x, int y, int time) {
    if (wei[x][y].l <= time && time <= wei[x][y].r) {
        return false;
    } else {
        return true;
    }
}

int bfs() {
    priority_queue<Node> q;
    memset(vis, 0, sizeof(vis));
    q.push(Node(0, 1, 1));
    vis[1][1][0] = 1;
    while (q.size()) {
        Node now = q.top();
        q.pop();
        if (now.x == n && now.y == m) {
            return now.step;
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (!C(nx, ny)) continue;
            if (!W(nx, ny, now.step+1)) continue;
            if (vis[nx][ny][now.step + 1] == 0) {
                q.push(Node(now.step+1, nx, ny));
                vis[nx][ny][now.step + 1] = 1;
            }
        }
    }
    return 0;
}

int main() {
  //  freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &r);
    memset(wei, 0, sizeof(wei));
    for (int i = 0; i < r; i++) {
        int x, y;
        WEI w;
        scanf("%d%d%d%d", &x, &y, &w.l, &w.r);
        wei[x][y] = w;
    }
    int ans = bfs();
    printf("%d", ans);
    return 0;
}
