#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#define BUY 2
#define SELL 3

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool isleap(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return true;
    return false;
}


int days(bool leap, int month)
{
    switch(month)
    {
    case 1:
        return 0;
    case 2:
        return 31;
    case 3:
        return leap ? 60 : 59;
    case 4:
        return leap ? 90 : 89;
    case 5:
        return leap ? 121 : 120;
    case 6:
        return leap ? 152 : 151;
    case 7:
        return leap ? 182 : 181;
    case 8:
        return leap ? 213 : 212;
    case 9:
        return leap ? 244 : 243;
    case 10:
        return leap ? 274: 273;
    case 11:
        return leap ? 305 : 304;
    case 12:
        return leap ? 335 : 334;
    }
}

int months(bool leap, int month)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return leap ? 29 : 28;
    }
}

int main() {
//  freopen("in.txt", "r", stdin);

    int year1,year2,month,week,day,leapcount = 0;
    cin >> month >>week >> day >> year1 >> year2;


    for(int i = 1850; i < year1; i++)
    {
        if(isleap(i))
            leapcount++;
    }

    for (int i = year1; i <= year2; i++) {
        bool leap = isleap(i);
        int totalday = (i-1850)*365 + leapcount + days(leap,month);
        int weekday = totalday % 7 + 2;
        int weekcount = day < weekday ? 1:2;
        int ans = 8 - weekday + (week - weekcount) * 7 + day;
        if(ans <= months(leap,month))
        {
            cout<<i<<"/";
            if(month < 10)
                cout<<0;
            cout<<month<<"/";
            if(ans<10)
                cout<<0;
            cout<<ans<<endl;
        }
        else
        {
            cout << "none" << endl;
        }
        if (leap) leapcount++;
    }
    return 0;
}
