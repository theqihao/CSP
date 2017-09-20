#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>
#define INF 0x003f3f3f


using namespace std;

enum {STRING, OBJECT};

struct Node {
    int type;
    string value;
};

map<string, Node> mm;


void  query(string s) {
    if (mm.find(s) != mm.end()) {
        Node ans = mm[s];
        if (ans.type == OBJECT) {
            printf("OBJECT\n");
        } else if (ans.type == STRING) {
            cout << "STRING " << ans.value << endl;
        }
    } else {
        printf("NOTEXIST\n");
    }
}

/*
5 4
{
"firstName": "John",
"lastName": "Smith",
"esc\\aped": "\"hello\""
}
firstName
lastName
xx
esc\aped


5 5
{
"firstName": "John",
"lastName": "Smith",
"esc\\aped": "\"hello\""
}
firstName
address
address.city
address.postal
esc\aped



10 5
{
"firstName": "",
"lastName": "Smith",
"address": {
"streetAddress": "2ndStreet",
"city": {"qihao": "xxx"},
"state": "NY"
},
"esc\\aped": "\"hello\""
}
firstName
address
address.city
address.city.qihao
esc\aped
*/

int main()
{
    int n, k;
    string ss;
    string s;
    cin >> n >> k;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        ss += s;
    }
    string objs[100];
    int objxb = 0;
    string temp;
    string key = "";
    string value = "";
    bool is_key = 1;
    bool is_zuo = 1;
    int yins = 0;
    int flag = 0;
    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == ' ' || ss[i] == '\n') continue;
        if (ss[i] == '{') {
            if (flag == 0) {
                flag = 1;
                continue;
            } else {
                if (objxb == 0) {
                    mm[key].type = OBJECT;
                    mm[key].value = key;
                    objs[objxb++] = key;
                    is_key = 1;
                } else {
                    string name = objs[0];
                    for (int a = 1; a < objxb; a++) {
                        name = name + "." + objs[a];
                    }
                    name = name + "." + key;
                    mm[name].type = OBJECT;
                    mm[name].value = name;
                    objs[objxb++] = name;
                    is_key = 1;
                }

                continue;
            }
        }
        if (ss[i] == '}') {
            if (objxb != 0) objxb--;
            is_key = 1;
            continue;
        }

        if (ss[i] == '"') {
            is_zuo = !is_zuo;
            yins++;
            if (yins % 2 == 0 && is_key == 0) {
                value = temp;
                temp = "";
                if (objxb == 0) {
                    mm[key].type = STRING;
                    mm[key].value = value;
                    is_key = 1;
                } else {
                    string node = objs[objxb-1];
                    key = node + "." + key;
                    mm[key].type = STRING;
                    mm[key].value = value;
                    is_key = 1;
                }

                //cout << "key =" << key << " v " << value << endl;
            }
            continue;
        }
        if (ss[i] == ':') {
            is_key = 0;
            key = temp;
            temp = "";
            continue;
        }
        if (ss[i] == ',') {
            is_key = 1;
            continue;
        }
        if (ss[i] == '\\') {
            i++;
            temp.insert(temp.end(), ss[i]);
            continue;
        }
        temp.insert(temp.end(), ss[i]);
    }


    for (int i = 0; i < k; i++) {
        cin >> s;
        query(s);
    }
    return 0;
}
