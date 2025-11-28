#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    string str;
    cin >> T;
    while (T--) {
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9') {
            cout << "https://www.luogu.com.cn/problem/P" << str << endl;
        } else {
            cout << "https://www.luogu.com.cn/problem/" << str << endl;
        }
    }
    return 0;
}