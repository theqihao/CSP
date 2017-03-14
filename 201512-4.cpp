#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x3fffffff
#define MAX_V 10005
using namespace std;



int V, E;
vector<int> G[MAX_V];
int du[MAX_V];
bool vis[MAX_V];
bool used[MAX_V][MAX_V];
int flag = 0;
stack<int> ans;

bool cmp(int x, int y) {
    return x < y;
}


void add_edge(int from, int to) {
    G[from].push_back(to);
    G[to].push_back(from);
    du[from]++;
    du[to]++;
}

void ola(int v) {
    if (flag == 1) return ;
    for (int i = 0; i < G[v].size(); i++) {
        int to = G[v][i];
        if (!used[v][to]) {
            used[v][to] = 1;
            used[to][v] = 1;
            ola(to);
        }
    }
    ans.push(v);
}

void dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        int to = G[v][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}

int main(void)
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    memset(du, 0, sizeof(du));
    memset(used, 0, sizeof(used));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    dfs(1);
    int error = 0;
    int odd_num = 0;
    for (int i = 1; i <= V; i++) {
        if (vis[i] == 0) {
            error = 1;
            break;
        }
        sort(G[i].begin(), G[i].end(), cmp);
        if (du[i] % 2 != 0) odd_num++;
    }
    if (odd_num > 2) {
        error = 1;
    }

    if (error == 1) {
        printf("-1");
    } else {
        memset(used, 0, sizeof(used));
        while (!ans.empty()) ans.pop();
        ola(1);
        //cout << "ola" << endl;
       // cout << ans.size() << endl;
        int flag = 0;
        while (!ans.empty()) {
            if (flag) cout << " ";
            else flag = 1;
            cout << ans.top();
            ans.pop();
        }
    }
    return 0;
}
