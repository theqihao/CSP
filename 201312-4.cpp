#include <string>
#include <sstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

typedef long long ll;
using namespace std;

const ll mod =1000000007;
ll a[1005][6];

int main() {
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    // 2    || 0, 1 ,3
    // 2, 0 || 1, 3
    // 2, 3 || 0, 1
    // 0, 2, 3 || 1
    // 0, 2, 1 || 3
    // 0, 1, 2, 3
    for (int i = 1; i <= n; i++) {
        a[i][0]  = 1;
        a[i][1]  = (a[i-1][0] + a[i-1][1] * 2) % mod;
        a[i][2]  = (a[i-1][0] + a[i-1][2]) % mod;
        a[i][3]  = (a[i-1][1] + a[i-1][2] + a[i-1][3] * 2) % mod;
        a[i][4]  = (a[i-1][1] + a[i-1][4] * 2) % mod;
        a[i][5]  = (a[i-1][3] + a[i-1][4] + a[i-1][5] * 2) % mod;
    }
    cout << a[n][5] << endl;
    return 0;
}

