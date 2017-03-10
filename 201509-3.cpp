#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    string moban;
    string rep;
};

int main() {
//    freopen("in.txt", "r", stdin);
    vector<string> v;
    vector<Node> tofind;
    string s;
    int snum;
    int fnum;
    cin >> snum >> fnum;
    getchar();
    for (int i = 0; i < snum; i++) {
        getline(cin, s);
        v.push_back(s);
    }
    for (int i = 0; i < fnum; i++) {
        Node node;
        getline(cin, s);
        node.moban = "";
        node.rep = "";
        string qian = "{{ ";
        string hou = " }}";

        int first = 1;
        int yinhao = 0;
        for (int i = 0; i < s.size(); i++) {
            if (first == 1) {
                if (s[i] != ' ') {
                    node.moban += s[i];

                } else {
                    first = 0;
                }

            } else {
                if (s[i] == '"') {
                    yinhao++;
                }

                if (yinhao == 0) {

                } else if (yinhao == 1) {
                    if (s[i] != '"')
                        node.rep += s[i];
                } else if (yinhao == 2) {
                    break;
                }
            }
        }
        node.moban = qian + node.moban + hou;
        tofind.push_back(node);
    }


    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < tofind.size(); j++) {
            std::string::size_type indx;
            while (1) {
                indx = v[i].find(tofind[j].moban);
                if (indx == std::string::npos) {
                    break;
                } else {
                    v[i].replace(indx, tofind[j].moban.size(), tofind[j].rep.data());
                }
            }
        }

        string qian  = "{{ ";
        string hou = " }}";
        std::string::size_type index1, index2;
        index1 = v[i].find(qian);
        index2 = v[i].find(hou);
        if (index1 != std::string::npos && index2 != std::string::npos) {
            v[i].replace(index1, index2 + 3 - index1, "");
        }
        cout << v[i] << endl;
    }


}

