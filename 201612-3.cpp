#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


struct QUAN {
    string name;
    int type;
    int num;
};

struct JIAO {
    string name;
    int num;
    QUAN QUANS[100];
};

struct USER {
    string name;
    int num;
    JIAO JIAOS[100];
};
vector<QUAN> Q;
vector<JIAO> J;
vector<USER> U;


void find1(string user, string quan) {
    int flag = 0;
    int flag2 = 0;
    int num = 0;
    for (int i = 0; i < U.size(); i++) {
        if (U[i].name == user) {
           // cout << U[i].name << endl;
            for (int j = 0; j < U[i].num; j++) {
             //   cout << U[i].JIAOS[j].name << endl;
                for (int k = 0; k < U[i].JIAOS[j].num; k++) {
                    if (U[i].JIAOS[j].QUANS[k].name == quan) {
                        if (U[i].JIAOS[j].QUANS[k].type ==  1) {
                            flag2 = 1;
                            num = max(num, U[i].JIAOS[j].QUANS[k].num);
                            //printf("%d\n", U[i].JIAOS[j].QUANS[k].num);
                            //break;
                        } else {
                            flag = 1;
                            break;
                        }

                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
    }
    if (flag2 == 0) {
        if (flag) printf("true\n");
        else printf("false\n");
    } else {
        printf("%d\n", num);
    }
}


void find2(string user, string quan) {

    for (int i = 0; i < quan.size(); i++) {
        if (quan[i] == ':') {
            quan[i] = ' ';
            break;
        }
    }

    stringstream ss(quan);
    string real;
    int num;
    ss >> real;
    ss >> num;

    int flag = 0;
    for (int i = 0; i < U.size(); i++) {
        if (U[i].name == user) {
           // cout << U[i].name << endl;
            for (int j = 0; j < U[i].num; j++) {
             //   cout << U[i].JIAOS[j].name << endl;
                for (int k = 0; k < U[i].JIAOS[j].num; k++) {
                    if (U[i].JIAOS[j].QUANS[k].name == real) {
                        if (U[i].JIAOS[j].QUANS[k].num >= num) {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
    }

    if (flag) printf("true\n");
    else printf("false\n");
}



int main() {
    //freopen("in.txt", "r", stdin);

    // input1
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        QUAN quan;
        if (s.find(":") == -1) {
            quan.type = 0;
            quan.num = 0;
            quan.name = s;
        } else {
            quan.type = 1;
            s[s.find(":")] = ' ';
            stringstream ss(s);
            ss >> quan.name;
            ss >> quan.num;
          //  cout << quan.num;
        }
        Q.push_back(quan);
    }
    // input2
    cin >> n;
    for (int i = 0; i < n; i++) {
        JIAO jiao;
        cin >> jiao.name;
        cin >> jiao.num;
        for (int i = 0; i < jiao.num; i++) {
            string s;
            cin >> s;
            QUAN quan;
            if (s.find(":") == -1) {
                quan.type = 0;
                quan.num = 0;
                quan.name = s;
            } else {
                quan.type = 1;
                s[s.find(":")] = ' ';
                stringstream ss(s);
                ss >> quan.name;
                ss >> quan.num;
            }
            jiao.QUANS[i] = quan;
        }
        J.push_back(jiao);
    }
    // input3
    cin >> n;
    for (int i = 0; i < n; i++) {
        USER user;
        cin >> user.name;
        cin >> user.num;
        for (int j = 0; j < user.num; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < J.size(); k++) {
                if (J[k].name == s) {
                    user.JIAOS[j] = J[k];
                    break;
                }
            }
        }
        U.push_back(user);
    }
    // find!!!
    cin >> n;
    for (int i = 0; i < n; i++) {

        string user_str, quan_str;
        cin >> user_str >> quan_str;
        // 1
        if (quan_str.find(":") == -1) {
            find1(user_str, quan_str);
        } else if (quan_str.find(":") != -1) {
            find2(user_str, quan_str);
        }
        // 2

        // 3
    }
}
