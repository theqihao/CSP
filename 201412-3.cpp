#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define INF 0x3fffffff
#define N 3500

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

typedef long long LL;
using namespace std;

int n;

struct Node {
    char name[16];
    double p;
    int s;
    bool is_true;
};


Node node[5003];


int main() {
    //freopen("in.txt", "r", stdin);
    int xb = 0;
    while (scanf("%s", node[xb].name) != EOF) {
        if (strcmp(node[xb].name, "cancel") == 0) {
            scanf("%d", &node[xb].s);
            node[xb].is_true = false;
            node[node[xb].s-1].is_true = false;
        } else {
            scanf("%lf%d", &node[xb].p, &node[xb].s);
            node[xb].is_true = true;
        }
        xb++;
    }
    /*
    int x = 0;
    for (int i = 0; i < xb; i++) {
        if (node[i].is_true == true) {
            node[x] = node[i];
            x++;
        }
    }
    */
    int x = xb;
    for (int i = 0; i < x; i++) {
        for (int j = i; j < x; j++) {
            if (node[i].p > node[j].p) {
                Node temp = node[i];
                node[i] = node[j];
                node[j] = temp;
            }
        }
    }

    double ansp = 0;
    LL anss = 0;
    for (int i = 0; i < x; i++) {
        double temp = node[i].p;
        LL sell = 0;
        LL buy = 0;
        for (int j = 0; j < x; j++) {
            if (strcmp(node[j].name, "buy") == 0 && node[j].is_true == true) {
                if (node[j].p >= temp) {
                    buy += node[j].s;
                }
            } else if (strcmp(node[j].name, "sell") == 0 && node[j].is_true == true) {
                if (node[j].p <= temp) {
                    sell += node[j].s;
                }
            }
        }
        LL ans = min(sell, buy);
        if (ans >= anss) {
            ansp = temp;
            anss = ans;
        }
    }
    printf("%.2lf %I64d", ansp, anss);
    return 0;
}
