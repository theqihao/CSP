#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;


int a[8001][8001];




int main() {
    int n, m;

    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &m);



    int x, y;
    int i, j, k;
    for (i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int ans = 0;
    for (i = 1; i <= n; i++) {
        for (j = i+1; j <= n; j++) {
            for (k = j+1; k <= n; k++) {
                if (i != j && i != k && j != k && a[i][j] == a[j][k] && a[i][j] == a[i][k]) {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
