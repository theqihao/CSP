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

typedef long long ll;

//ll a[100005];
ll bit[100005];

int n, k;

ll sum(ll i) {
    ll s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(ll i, ll x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

/*

5 3
1 2 3 4 5
2 1 2
2 1 3
2 1 5

5 3
1 2 3 4 5
2 1 5
1 1 3 2
2 1 5
*/

int main()
{
    scanf("%d%d", &n, &k);
    memset(bit, 0, sizeof(bit));
    ll x;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        add(i, x);
    }

    for (int i = 0; i < k; i++) {
        int op;
        scanf("%d", &op);
        int l, r, v;
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &v);
            for (int j = l; j <= r; j++) {
                ll cur = sum(j) - sum(j-1);
                if (cur % v == 0) {
                    ll sub = (cur / v) - cur;
                    add(j, sub);
                }
            }
        } else if (op == 2) {
            scanf("%d%d", &l, &r);
            //printf("%lld\n", (ll)(sum(r) - sum(l-1)));
            cout << (ll)(sum(r) - sum(l-1)) << endl;
        }
    }
    return 0;
}
