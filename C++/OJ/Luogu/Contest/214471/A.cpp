#include<bits/stdc++.h>
using namespace std;
int read(){
    int s = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int main() {
    int T;
    T = read();
    while (T--) {
        int a, b, n;
        a = read();
        b = read();
        n = read();
        if (a > b) {
            swap(a, b);
        }
        bool flag = 1;
        while (1) {
            if (a == n || b == n) {
                flag = 0;
                break;
            }
            if (b >= n) {
                break;
            }
            a = a + b;
            if (a > b) {
                swap(a, b);
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}