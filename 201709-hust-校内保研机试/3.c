#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

char a[256];
char temp[256];
char ans[256];
int vis[256];
int len = 0;
int txb = 0;

void dfs(char *s, int re, int index)  {
    if (re == 0) {
        if (strcmp(ans, temp) > 0) {
            strcpy(ans, temp);
        }
        return ;
    }

    int i = 0;
    for (i = index; i < strlen(s); i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            temp[txb++] = s[i];
            temp[txb] = '\0';
            dfs(s, re-1, i);
            temp[--txb] = '\0';
            vis[i] = 0;
        }
    }

}

int main() {
    int n;
    while (scanf("%s", a)) {
        if (strcmp(a, "0") == 0) break;
        int k;
        scanf("%d", &k);

        //printf("%s\n", a);

        if (k >= strlen(a)) {
            printf("0\n");
            continue;
        }

        len = strlen(a);
        strcpy(temp, a);
        strcpy(ans, a);
        ans[len-k] = '\0';
        memset(vis, 0, sizeof(vis));

        dfs(a, len-k, 0);

        k = 0;
        int flag = 0;
        for (k = 0; k < strlen(ans); k++) {
            if (flag == 0 && ans[k] == '0') {
            } else {
                flag = 1;
            }

            if (flag) {
                printf("%c", ans[k]);
            }
        }


        printf("\n");
    }

    return 0;
}
