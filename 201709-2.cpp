#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <set>
#define INF 0x003f3f3f


using namespace std;

struct Node {
    int id;
    int s;
    int e;
    /*
    bool operator < (const Node b) {
        if (e == b.e) {
            return id < b.id;
        } else {
            return e < b.e;
        }
    }
    */
};



Node node[1005];
Node start[1005];
Node stop[1005];
int a[1005];
//bool vis[11000];
int n, k;

void my_get(int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            a[i] = 0;
            break;
        }
    }
}

void my_put(int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = x;
            break;
        }
    }
}

bool cmp_stop(const Node &a, const Node &b) {
    return a.id < b.id;
}

/*
5 3
4 3 6
3 2 7
2 2 7
*/

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    //memset(vis, 0, sizeof(vis));
    //int max_time = 0;
    set<int> ss;
    for (int i = 0; i < k ;i++) {
        scanf("%d%d%d", &node[i].id, &node[i].s, &node[i].e);
        node[i].e += node[i].s;
        //vis[node[i].s] = 1;
        //vis[node[i].e] = 1;
        //max_time = max(max_time, node[i].e);
        ss.insert(node[i].s);
        ss.insert(node[i].e);
    }

    //sort(node, node+k);
    for (set<int>::iterator it = ss.begin(); it != ss.end(); it++) {
    //for (int i = 1; i <= max_time; i++) {
        //if (vis[i] == 0) continue;
        int i = *it;
        int ns = 0;
        int ne = 0;
        for (int j = 0; j < k; j++) {
            if (node[j].s == i) {
                start[ns++] = node[j];
                //my_get(node[j].id);
            } else if (node[j].e == i) {
                stop[ne++] = node[j];
                //my_get(node[j].id);
            }
        }
        //printf("%d %d\n", ns, ne);
        if (ne != 0) {
            sort(stop, stop+ne, cmp_stop);
        }
        for (int j = 0; j < ne; j++) {
            my_put(stop[j].id);
        }
        for (int j = 0; j < ns; j++) {
            my_get(start[j].id);
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (flag == 0) {
            flag = 1;
            printf("%d", a[i]);
        } else {
            printf(" %d", a[i]);
        }
    }

    return 0;
}
