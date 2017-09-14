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

struct XX {
    char v;
    bool can;
};

struct ML {
    XX xx[52];
    int num;
};

struct Node {
    char v;
    bool is_can;
    char can[256];
};

Node ans[52];
int ansxb = 0;

void insert_ans(char v, int is_can, char *s) {
    int i  = 0;
    int flag = 0;
    int xb = 0;
    for (i = 0; i < ansxb; i++) {
        if (ans[i].v == v) {
            flag = 1;
            xb = i;
            break;
        }
    }
    if (flag == 0) {
        ans[ansxb].v = v;
        ans[ansxb].is_can = is_can;
        if (is_can) {
            memcpy(ans[ansxb].can, s, strlen(s)+1);
        }
        ansxb++;
    } else {
        ans[xb].v = v;
        ans[xb].is_can = is_can;
        if (is_can == 1) {
            memcpy(ans[xb].can, s, strlen(s)+1);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    char s[512];
    scanf("%s", s);
    ML ml;
    ml.num = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ':') {
            ml.xx[ml.num-1].can = 1;
        } else {
            ml.xx[ml.num].v = s[i];
            ml.xx[ml.num].can = 0;
            ml.num++;
        }
    }
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        //mygetline(s);
        gets(s);
        //printf("%s, len = %d\n", s, strlen(s));
        int flag = 0;
        char temp[128];
        int txb = 0;
        char pre_lm = 0;
        int pre_is_can = 0;
        int error = 0;
        for (int j = 0; j <= strlen(s); j++) {
            if (flag == 0) {
                if (s[j] == ' ') {
                    flag = 1;
                }
                continue;
            }
            if (s[j] == ' ' || s[j] == '\0') {
                temp[txb] = '\0';
                if (s[j-1] == ' ') continue;
               // printf("%s, len = %d\n", temp, strlen(temp));
                if (pre_is_can) {
                    pre_is_can = 0;
                    insert_ans(pre_lm, 1, temp);
                } else {
                    if (strlen(temp) == 2 && temp[0] == '-' && 'a' <= temp[1] && temp[1] <= 'z') {
                        int findd = 0;
                        for (int k = 0; k < ml.num; k++) {
                            if (ml.xx[k].v == temp[1]) {
                                findd = 1;
                                if (ml.xx[k].can == 1) {
                                    pre_is_can = 1;
                                    pre_lm = ml.xx[k].v;
                                } else {
                                    pre_is_can = 0;
                                    insert_ans(ml.xx[k].v, 0, 0);
                                }
                                break;
                            }
                        }
                        if (findd == 0) {
                            error = 1;
                            break;
                        }
                    } else {
                        error = 1;
                        break;
                    }
                }
                txb = 0;
            } else {
                temp[txb++] = s[j];
            }
            if (error == 1) {
                break;
            }
        }
        //printf("%d\n", ansxb);
        // sort
        for (int x = 0; x < ansxb; x++) {
            for (int y = x; y < ansxb; y++) {
                if (ans[x].v > ans[y].v) {
                    Node temp = ans[x];
                    ans[x] = ans[y];
                    ans[y] = temp;
                }
            }
        }
        printf("Case %d: ", i);
        for (int x = 0; x < ansxb; x++) {

            if (ans[x].is_can == 0) {
                printf("-%c ", ans[x].v);
            } else {
                printf("-%c ", ans[x].v);
                printf("%s ", ans[x].can);
            }
        }
        printf("\n");
        ansxb = 0;
    }
    return 0;
}
