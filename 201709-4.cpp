#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>
#include <queue>
#define INF 0x003f3f3f
#define N

using namespace std;

struct Node {
    int to, w;
};

vector<Node> G[1005];
bool vis[1005][1005];
bool used[1005];


void add_edge(int u, int v, int w) {
    Node node;
    node.to = v;
    node.w = w;
    G[u].push_back(node);
}

/*


4 5
1 2
2 3
1 3
2 4
3 4
*/

int main()
{
    int V, E;
    scanf("%d%d", &V, &E);
    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v, 1);
    }
    memset(vis, 0, sizeof(vis));
    for (v = 1; v <= V; v++) {
        vis[v][v] = 1;
        memset(used, 0, sizeof(used));
        queue<int> q;
        q.push(v);
        used[v] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < G[cur].size(); i++) {
                Node edge = G[cur][i];
                int to = edge.to;
                if (used[to] == 0) {
                    used[to] = 1;
                    vis[cur][to] = 1;
                    vis[v][to] = 1;
                    q.push(to);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= V; i++) {
        memset(used, 0, sizeof(used));
        int sum = 0;
        for (int j = 1; j <= V; j++) {
            used[j] = vis[i][j] || vis[j][i];
            sum += used[j];
        }
        if (sum == V) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
