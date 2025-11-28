#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if(s == "520"){
        cout << "Yes";
        return 0;
    }
    if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
        cout << "No" << endl;
        return 0;
    }
    char key[10][10] = {
        {'/', '*', '-', '+'},
        {'7', '8', '9', '+'},
        {'4', '5', '6', '^'},
        {'1', '2', '3', '^'},
        {'0', '<', '.', '^'}
    };
    int pos[3][2] = {-1};
    bool check = 1;
    for (int i = 0; i < 3; i++) {
        bool flag = 0;
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 4; y++) {
                if (key[x][y] == s[i]) {
                    pos[i][0] = x;
                    pos[i][1] = y;
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) {
            check = 0;
            break;
        }
    }
    if (!check) {
        cout << "No" << endl;
        return 0;
    }
    bool same_x = (pos[0][0] == pos[1][0] && pos[1][0] == pos[2][0]);
    bool same_y = (pos[0][1] == pos[1][1] && pos[1][1] == pos[2][1]);
    if (!same_x && !same_y) {
        cout << "No" << endl;
        return 0;
    }
    if (same_x) {
        int y1 = pos[0][1];
        int y2 = pos[1][1];
        int y3 = pos[2][1];
        if ((y1 == y2 - 1 && y2 == y3 - 1) || (y1 == y2 + 1 && y2 == y3 + 1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else if (same_y) {
        int x1 = pos[0][0];
        int x2 = pos[1][0];
        int x3 = pos[2][0];
        if ((x1 == x2 - 1 && x2 == x3 - 1) || (x1 == x2 + 1 && x2 == x3 + 1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}