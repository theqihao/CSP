#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;



int vis[128];
char s[128];
char d[128];


int find(char *s, int begin, char c) {
    int i = begin;
    int flag = 0;
    for (i = begin; i <= strlen(s); i++) {
        if (vis[i] == 0 && s[i] == c) {
            vis[i] = 1;
            flag = 1;
            return i;
        }
    }
    return -1;
}

int slove(int x, int y) {
    int i, j;
    if (y == strlen(d) - 1) {
        return 0;
    }
    int error = 0;
    for (j = y+1; j < strlen(d); i++) {
        if (d[j] == '*') {

            error = slove(i, j);
            if (error == 1) {
                break;
            } else {
                continue;
            }
        }
        if (d[j] == '?') {
            x++;
            continue;
        }

        int pos = find(s, x, d[j]);
        if (pos == -1) {
            error = 1;
            break;
        }
        x = pos;
    }
    return error;
}

int find2(int i, int j) {
    int error = 0;
    for (i; i < strlen(s); i++) {
        if (d[j] == '?') {
            j++;
            //printf("?????\n");
            continue;
        } else if (d[j] == '*') {
            if (j == strlen(d)-1) {
                error = 0;
                break;
            }
            //printf("**\n");
            while (d[j+1] == '*') {
                j++;
            }
            while (d[j+1] == '?') {
                i++;
                j++;
            }
            memset(vis, 0, sizeof(vis));
            int pos = find(s, i, d[j+1]);
            //printf("pos = %d\n", pos);
            if (pos == -1) {
                error = 1;
                /// error =
                break;
            } else {
                i = pos;
               // printf("i = pos\n");
                j += 2;
            }
        } else {
            if (d[j] != s[i]) {
                error = 1;
                break;
            } else {
                j++;
            }

        }
    }
    return error;
}


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", s, d);
        int i, j, k;
        int error = 0;
        memset(vis, 0, sizeof(vis));
        j = 0;
        for (i = 0; i < strlen(s); i++) {
            //printf("%c  %c\n", s[i], d[j]);
            /*
            if (i >= strlen(d)) {
                error = 1;
                break;
            }
            */
            if (d[j] == '?') {
                j++;
                //printf("?????\n");
                continue;
            } else if (d[j] == '*') {
                if (j == strlen(d)-1) {
                    error = 0;
                    break;
                }
                //printf("**\n");
                while (d[j+1] == '*') {
                    j++;
                }
                while (d[j+1] == '?') {
                    i++;
                    j++;
                }
                memset(vis, 0, sizeof(vis));
                int pos = find(s, i, d[j+1]);
                //printf("pos = %d\n", pos);
                if (pos == -1) {
                    error = 1;
                    /// error =
                    break;
                } else {
                    i = pos;
                   // printf("i = pos\n");
                    j += 2;

                    int pos2 = pos;
                    while (pos2 != -1) {
                        pos2 = find(s, pos2+1, d[j+1]);
                        error = find2(pos2, j+2);
                        if (error == 1) {
                            break;
                        }
                    }
                    if (error == 0) {
                        break;
                    }
                }
            } else {
                if (d[j] != s[i]) {
                    error = 1;
                    break;
                } else {
                    j++;
                }

            }
        }

        if (error == 1) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }


    return 0;
}
