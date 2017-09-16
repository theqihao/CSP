
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <sstream>
#define INF 0x3fffffff


#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

using namespace std;
typedef long long ll;

#define N 10005
int n, m;
int d[N];
int pre[N];

struct edge {
    int to, w;
};

struct Node {
    int to;
    int cost;
    Node (int _to, int _cost) {
        to = _to;
        cost = _cost;
    }
};

vector<edge> G[N];

void dijk(int s) {
    for (int i = 0; i <= n; i++) {
        pre[i] = INF;
        d[i] = INF;
    }

    queue<Node> Q;
    Q.push(Node(1, 0));
    d[s] = 0;

    while (!Q.empty()) {
        Node cur = Q.front(); Q.pop();
        int v = cur.to;
        //if (cur.cost > d[v]) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            int to = e.to;
            int w = e.w;
            if (d[to] > d[v] + w) {
                d[to] = d[v] + w;
                pre[to] = w;
                Q.push(Node(to, d[to]));
            } else if ((d[to] == d[v] + w) && (w < pre[to])) {
                pre[to] = w;
            }
        }
    }
}


void add_edge(int u, int v, int w) {
    edge e;
    e.w = w;
    e.to = v;
    G[u].push_back(e);
    e.to = u;
    G[v].push_back(e);
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    dijk(1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += pre[i];
    }
    printf("%d", ans);
    return 0;
}
