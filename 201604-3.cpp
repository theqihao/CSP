#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main() {
    //freopen("in.txt", "r", stdin);

    int n;
    string cur;

    cin >> n;
    cin >> cur;

    getchar();
    for (int i = 0; i < n; i++) {
        string s;
       // cin >> s;
        getline(cin, s);
        if (s == "") {
            cout << cur << endl;
            continue;
        }
        if (s[0] != '/') s = cur + "/" + s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                s[i] = ' ';
            }
        }


        stringstream ss(s);

        string temp;
        vector<string> v;
        v.clear();
        while (ss >> temp) {
            if (temp == ".") continue;
            else if (temp == "..") {
                if (!v.empty()) v.pop_back();
            }
            else v.push_back(temp);

        }
        cout << "/";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                cout << "/";
            }
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}
