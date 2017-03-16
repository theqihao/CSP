#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#define EE 0
#define NN 90
#define WW 180
#define SS 270

using namespace std;

struct Node {
    int num;
    int to;
    Node() : num(0), to(0) {

    }
};

Node G[105][105];

struct COM {
    int num;
    int repeat;
        char action;
};

COM com[105];

struct Point {
    int x;
    int y;
};

Point pos[105];

int main() {
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // 1 <= fx <= m
        // 1 <= fy <= n
        memset(G, 0, sizeof(G));
        memset(pos, 0, sizeof(pos));
        memset(com, 0, sizeof(com));
        int num, commed;
        cin >> num >> commed;
        for (int i = 1; i <= num; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            int fx = m-y+1;
            int fy = x;
            pos[i].x = fx;
            pos[i].y = fy;
            G[fx][fy].num = i;
            if (c == 'E') {
                G[fx][fy].to = EE;
            } else if (c == 'W') {
                G[fx][fy].to = WW;
            } else if (c == 'N') {
                G[fx][fy].to = NN;
            } else if (c == 'S') {
                G[fx][fy].to = SS;
            }
        }

        for (int i = 0; i < commed; i++) {
            cin >> com[i].num >> com[i].action >> com[i].repeat;
        }
        int error = 0;
        for (int i = 0; i < commed; i++) {
            int num = com[i].num;
            char c = com[i].action;
            int rep = com[i].repeat;
            int x = pos[num].x;
            int y = pos[num].y;
            //cout << c << endl;
            switch (c) {
            case 'F':
                if (G[x][y].to == 0) {
                    G[x][y].num = 0;
                    for (int i = 0; i < rep; i++) {
                        y++;
                        if (y > n) {
                            error = 1;
                            printf("Robot %d crashes into the wall\n", num);
                            break;
                        }
                        if (G[x][y].num != 0) {
                            error = 1;
                            printf("Robot %d crashes into robot %d\n", num, G[x][y].num);
                            break;
                        }
                    }
                    if (error == 0) {
                        G[x][y].num = num;
                        G[x][y].to = 0;
                        pos[num].x = x;
                        pos[num].y = y;
                    }
                } else if (G[x][y].to == 90) {
                    G[x][y].num = 0;

                    for (int i = 0; i < rep; i++) {
                        x--;
                     //   cout << x << " " << y << endl;
                        if (x < 1) {
                            error = 1;
                            printf("Robot %d crashes into the wall\n", num);
                            break;
                        }
                        if (G[x][y].num != 0) {
                            error = 1;
                            printf("Robot %d crashes into robot %d\n", num, G[x][y].num);
                            break;
                        }
                    }
                    if (error == 0) {
                        G[x][y].num = num;
                        G[x][y].to = 90;
                        pos[num].x = x;
                        pos[num].y = y;
                    }
                } else if (G[x][y].to == 180) { // y-1
                    G[x][y].num = 0;
                    for (int i = 0; i < rep; i++) {
                        y--;
                        if (y < 1) {
                            error = 1;
                            printf("Robot %d crashes into the wall\n", num);
                            break;
                        }
                        if (G[x][y].num != 0) {
                            error = 1;
                            printf("Robot %d crashes into robot %d\n", num, G[x][y].num);
                            break;
                        }
                    }
                    if (error == 0) {
                        G[x][y].num = num;
                        G[x][y].to = 180;
                        pos[num].x = x;
                        pos[num].y = y;
                    }
                } else if (G[x][y].to == 270) { // x + 1
                    G[x][y].num = 0;
                    for (int i = 0; i < rep; i++) {
                        x++;
                        if (x > m) {
                            error = 1;
                            printf("Robot %d crashes into the wall\n", num);
                            break;
                        }
                        if (G[x][y].num != 0) {
                            error = 1;
                            printf("Robot %d crashes into robot %d\n", num, G[x][y].num);
                            break;
                        }
                    }
                    if (error == 0) {
                        G[x][y].num = num;
                        G[x][y].to = 270;
                        pos[num].x = x;
                        pos[num].y = y;
                    }
                }
                break;
            case 'L':
                for (int i = 0; i < rep; i++) {
                    G[x][y].to = (G[x][y].to + 90) % 360;
                }
                break;
            case 'R':
                for (int i = 0; i < rep; i++) {
                    G[x][y].to = (G[x][y].to - 90) % 360;
                }
                G[x][y].to = (G[x][y].to + 360) % 360;
                break;
            default:
                break;
            }
            if (error == 1) {
                break;
            }
        }
        if (error == 0) {
            printf("OK\n");
        }

    }
    return 0;
}
