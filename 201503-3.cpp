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

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    return false;
}

int days_till_month(bool leap, int month) {
    if (leap) {
        months[2] = 29;
    } else {
        months[2] = 28;
    }
    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += months[i];
    }
    return sum;
}

int day_pre_month(bool leap, int month) {
    if (leap) {
        months[2] = 29;
    } else {
        months[2] = 28;
    }
    return months[month];
}

int main() {
    //freopen("in.txt", "r", stdin);
    int m, w, d, y1, y2;
    int leaps = 0;
    scanf("%d%d%d%d%d", &m, &w, &d, &y1, &y2);
    for (int i = 1850; i < y1; i++) {
        if (isleap(i)) {
            leaps++;
        }
    }
    for (int i = y1; i <= y2; i++) {
        bool leap = isleap(i);
        int totalday = (i-1850)*365 + leaps + days_till_month(leap, m);
        int weekday = (totalday+2) % 7;
        weekday = weekday == 0 ? 7 : weekday;
        int weekcount = d >= weekday ? 2 : 1;
        int ans = 8 - weekday + (w-weekcount) * 7 + d;
        if (ans <= day_pre_month(leap, m)) {
            printf("%d/%02d/%02d\n", i, m, ans);
        } else {
            printf("none\n");
        }
        leaps += leap;
    }
    return 0;
}
