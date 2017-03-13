#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x3fffffff
#define MAX_V 20005
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int V, E, K;

struct edge {
    int to;
    int w;
};

int d[MAX_V+1];
int pa[MAX_V];
int high[MAX_V];
vector<edge> G[MAX_V];

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

void add_edge(int u, int v) {
    edge e;
    e.w = 1;
    e.to = v;
    G[u].push_back(e);
    e.to = u;
    G[v].push_back(e);
}

void init(int n) {
    memset(high, 0, sizeof(high));
    for (int i = 0; i <= n; i++) {
        pa[i] = i;
    }
}

void dijkstra(int s) {
    priority_queue<pp, vector<pp>, greater<pp> > q;
    fill(d, d+MAX_V, INF);
    d[s] = 0;
    q.push(pp(0, s));

    while (q.size()) {
        pp p = q.top();
        q.pop();
        int v = p.second;
        int w = p.first;
        if (d[v] < w) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.w) {
                d[e.to] = d[v] + e.w;
                q.push(pp(d[e.to], e.to));
            }
        }
    }
}

int main(void)
{
   // freopen("in.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    init(V+E+5);
    for (int i = 2; i <= V; i++) {
        int x;
        scanf("%d", &x);
        pa[i] = x;
        add_edge(i, x);
    }
    for (int i = 1; i <= E; i++) {
        int x;
        scanf("%d", &x);
        pa[i+V] = x;
        add_edge(i+V, x);
    }

    int index = 0;
    int max_deep = 0;
    for (int i = 2; i <= E+V; i++) {
        int deep = 0;
        int num = i;
        while(1) {
            if (num == 1) {
                break;
            }
            deep++;
            num = pa[num];
        }
       // cout << deep << endl;
        if (deep > max_deep) {
            max_deep = max(max_deep, deep);
            index = max(index, i);
        }
    }
    //cout << index << endl;
    dijkstra(index);
    int ans = 0;
    for (int i = 1; i <= V+E; i++) {
        if (d[i] != INF) {
           // cout << d[i] << endl;
            ans = max(ans, d[i]);
        }
    }
    printf("%d", ans);
    return 0;
}
