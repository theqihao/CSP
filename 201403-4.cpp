#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
#define INF 0x3fffffff

#define MAX_V 333
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

struct Point {
    int x;
    int y;
    int isadd;
}point[MAX_V];

struct Node {
    int id;
    int step;
    int adds;
    Node(int x = 0, int y = 0, int z = 0) {
        id = x;
        step = y;
        adds = z;
    }
};

int m, n, k, r;
int d[MAX_V];
queue<Node> q;


/*
struct edge {
    int to;
    int w;
};

vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<pp, vector<pp>, greater<pp> > q;
    fill(d, d+300, INF);
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
*/
double getline(int id1, int id2) {
    int x1 = point[id1].x;
    int y1 = point[id1].y;
    int x2 = point[id2].x;
    int y2 = point[id2].y;
    double ans = pow(pow(abs(x1-x2), 2.0) + pow(abs(y1-y2), 2.0)*1.0,  0.5);
    return ans;
}

int bfs() {
    fill(d, d+300, INF);
    d[0] = 0;
    q.push(Node(0, 0, 0));

    while (q.size()) {
        Node now = q.front();
        q.pop();
        for (int i = 1; i < n+m; i++) {
            if (now.id != i && getline(i, now.id) <= r*1.0 && d[i] > 1+now.step && now.adds+point[i].isadd <= k) {
                d[i] = 1+now.step;
                q.push(Node(i, d[i], now.adds+point[i].isadd));
            }
        }
    }
    return d[1];
}



int main() {
 //   freopen("in.txt", "r", stdin);
    // input
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 0; i < n+m; i++) {
        scanf("%d%d", &point[i].x, &point[i].y);
        if (i >= n) {
            point[i].isadd = 1;
        } else {
            point[i].isadd = 0;
        }
    }
    cout << bfs() - 1 << endl;
    return 0;
}
