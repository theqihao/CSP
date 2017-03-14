#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x0ffffff
#define N 1005
using namespace std;

typedef unsigned long long ll;

int V;
ll num[N];
ll sum[N];
ll dp[N][N];

int main(void)
{
  //  freopen("in.txt", "r", stdin);
    scanf("%d", &V);
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= V; i++) {
        scanf("%d", &num[i]);
        sum[i] = sum[i-1] + num[i];
        dp[i][i] = 0;
    }
    /*
    1¡¢dp[i][j]=0 (i==j)
    2¡¢dp[i][j]=min(dp[i][k]+dp[k][j])+sum[i][j] (i!=j)
    */
    for (int len = 2; len <= V; len++) {
        for (int i = 1; i + len - 1 <= V; i++) {
            int j = i + len - 1;
            int sumij = sum[j] - sum[i-1];
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sumij);
            }
        }
    }
    printf("%lld", dp[1][V]);
    return 0;
}
