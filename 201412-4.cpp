#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX_V 1005
using namespace std;

int V, E, K;
int flag, n;
int u, v, w;

struct edge {
    int u,v;
    int w;
};

edge es[MAX_V * MAX_V];
int pa[MAX_V];
int high[MAX_V];

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}
// 减号比大于号更快
int cmp2(const void *a, const void *b){

    return ((edge *)a)->w - ((edge *)b)->w;
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
    flag--;
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
    init(V); // 初始化并查集
    int ans = 0;
    for (int i = 0; i < E; i++) {
        edge* e = &es[i];
        if (!same(e->u, e->v)) {
            //cout << e.u << " " << e.v << endl;
            unite(e->v, e->u);
            ans += e->w;
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
    int ans = kruskal();
    printf("%d", ans);
    return 0;
}
