#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

struct Node {
    int type;
    string content;
    vector<string> lis;
};

vector<Node> v;

int main()
{

    string line;
    string duan = "";
    int duan_flag = 0;
    int kong_flag = 0;
    int li_flag = 0;
    Node temp;
    while (getline(cin, line)) {
        // kong
        if (line == "") {
            kong_flag = 1;
            if (duan_flag == 1 && kong_flag == 1) {
                string xxx = duan.substr(0, duan.size() - 1);
                temp.type = 1;
                temp.content = xxx;
                v.push_back(temp);
                duan = "";
                duan_flag = 0;
            } else if (li_flag == 1) {
                v.push_back(temp);
                li_flag = 0;
            }
            temp.content = "";
            temp.type = 0;
            temp.lis.clear();
            continue;
        }
        // ######
        if (line[0] == '#') {
            temp.type = 0;
            int i;
            for (i = 0; i < line.size(); i++) {
                if (line[i] == '#') {
                    temp.type = temp.type * 10 + 2;
                } else {
                    break;
                }
            }
            string s = "";
            while (line[i] == ' ') {
                i++;
            }

            for (; i < line.size(); i++) {
                s += line[i];
            }
            temp.content = s;
            v.push_back(temp);
        } else if (line[0] == '*') {
            li_flag = 1;
            temp.type = 3;

            string s = "";
            int i = 1;
            while (line[i] == ' ') {
                i++;
            }
            for (; i < line.size(); i++) {
                s += line[i];
            }
            temp.lis.push_back(s);
        } else if (line.find("_") != -1 || line.find("[") != -1 && line.find("]") != -1) {
            int flag = 0;
            while (line.find("_") != -1) {
                int pos = line.find("_");
                if (flag == 0) {
                    line.replace(pos, 1, "<em>");
                    flag = 1;
                } else {
                    line.replace(pos, 1, "</em>");
                    flag = 0;
                }
            }
            temp.content = line;
            string qian = "";
            string text = "";
            string link = "";
            string hou  = "";
            if (line.find("[") != -1 && line.find("]") != -1) {
                int pos = line.find("[");
                for (int i = 0; i < pos; i++) {
                    qian += line[i];
                }
                for (int i = pos+1; line[i] != ']'; i++) {
                    text += line[i];
                }
                pos = line.find("(");
                for (int i = pos+1; line[i] != ')'; i++) {
                    link += line[i];
                }
                for (int i = line.find(")")+ 1; i < line.size(); i++) {
                    hou += line[i];
                }
                temp.content = qian + "<a href=\"" + link + "\">" + text + "</a>" + hou;
            }




            temp.type = 4;
            v.push_back(temp);
        } else {
            duan_flag = 1;
            duan += line;
            duan += "\n";
            kong_flag = 0;
        }
    }

    if (duan_flag == 1 && duan != "") {
        string xxx = duan.substr(0, duan.size() - 1);
        Node temp;
        temp.type = 1;
        temp.content = xxx;
        v.push_back(temp);
        duan = "";
        duan_flag = 0;
    } else if (li_flag == 1) {
        v.push_back(temp);
        li_flag = 0;
    }

    //cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
       // cout << v[i].type << v[i].content << endl;
        switch(v[i].type) {
            case 2:
                cout << "<h1>" << v[i].content << "</h1>" << endl;
                break;
            case 22:
                cout << "<h2>" << v[i].content << "</h2>" << endl;
                break;
            case 222:
                cout << "<h3>" << v[i].content << "</h3>" << endl;
                break;
            case 2222:
                cout << "<h4>" << v[i].content << "</h4>" << endl;
                break;
            case 22222:
                cout << "<h5>" << v[i].content << "</h5>" << endl;
                break;
            case 222222:
                cout << "<h6>" << v[i].content << "</h6>" << endl;
                break;
            case 1:
                cout << "<p>" << v[i].content << "</p>" << endl;
                break;
            case 3:
                cout << "<ul>" << endl;
                for (int j = 0; j < v[i].lis.size(); j++) {
                    cout << "<li>" << v[i].lis[j] << "</li>" << endl;
                }
                cout << "</ul>" << endl;
                break;
            case 4:
                cout << "<p>" << v[i].content << "</p>" << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
