#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x3fffffff
#define MAX_V 100005
using namespace std;

int V, E;
int u, v, w;

struct edge {
    int u,v;
    int w;
};

struct edge2 {
    int to;
    int w;
};

edge es[200000 + 5];
int pa[MAX_V];
int high[MAX_V];


typedef long long ll;
typedef pair<int, int> pp;
int d[MAX_V];
int pre[MAX_V];

vector<edge2> G[MAX_V];


void add_edge(int u, int v, int w) {
    edge2 e;
    e.w = w;
    e.to = v;
    G[u].push_back(e);
    e.to = u;
    G[v].push_back(e);
}

void dijkstra(int s) {
    priority_queue<pp, vector<pp>, greater<pp> > q;
    fill(d, d+MAX_V, INF);
    memset(pre, -1, sizeof(pre));
    d[s] = 0;
    q.push(pp(0, s));

    while (q.size()) {
        pp p = q.top();
        q.pop();
        int v = p.second;
        int w = p.first;
        if (d[v] < w) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge2 e = G[v][i];
            if (d[e.to] > d[v] + e.w) {
                d[e.to] = d[v] + e.w;
                pre[e.to] = v;
                q.push(pp(d[e.to], e.to));
            }
        }
    }
}




bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

void init(int n) {
    memset(high, 0, sizeof(high));
    for (int i = 0; i <= n; i++) {
        pa[i] = i;
        //high[i] = 0;
    }
}

int _find(int x) {
    if (pa[x] == x) return pa[x];
    else return pa[x] =  _find(pa[x]);
}

int same(int x, int y) {
    return _find(x) == _find(y);
}

void unite(int x, int y) {
    x = _find(x);
    y = _find(y);
    if (x == y) return ;
    if (high[x] < high[y]) {
        pa[x] = y;
    } else {
        pa[y] = x;
        if (high[x] == high[y]) high[x]++;
    }
}



int kruskal() {
    sort(es, es + E, cmp);
    //qsort(es, E, sizeof(edge), cmp2);
    init(V+1);
    int ans = 0;
    for (int i = 0; i < E; i++) {
        edge* e = &es[i];
        if (!same(e->u, e->v)) {
            //cout << e.u << " " << e.v << endl;
            unite(e->v, e->u);
            ans += e->w;
            add_edge(es[i].u, es[i].v, es[i].w);
            //result = max(result, e->w);
        }
    }
    return ans;
}

int main(void)
{
  //  freopen("in.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);

    }
    kruskal();
    dijkstra(1);
    int result = 0;

    vector<int> path;
    int t = V;
    for (; t != -1; t = pre[t]) path.push_back(t);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size()-1; i++) {
        for (int j = 0; j < G[path[i]].size(); j++) {
            if (G[path[i]][j].to == path[i+1]) {
                result = max(result, G[path[i]][j].w);
                break;
            }
        }
    }
    printf("%d", result);
    return 0;
}
