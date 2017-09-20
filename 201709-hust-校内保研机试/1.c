#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;


int get_sum(int x) {
    int sum = 1;
    int i;
    for (i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            if (i == x/i) {
                sum += i;
            } else {
                sum += i;
                sum += x/i;
            }
        }
    }
    return sum;
}


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int i;
        int flag = 0;
        int ans = 0;
        for (i = x; i <= y; i++) {
            ans = get_sum(i);
            if (i!= ans && x <= ans && ans <= y && get_sum(ans) == i) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("%d %d\n", i, ans);
        } else {
            printf("No\n");
        }

    }
    return 0;
}
