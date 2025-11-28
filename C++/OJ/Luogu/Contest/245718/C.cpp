#include<bits/stdc++.h>
using namespace std;
char s[100], tmp[105];
int main() {
    cin >> s;
    int len = strlen(s), zu = (len + 1) / 2, glen = 2;
    for (int i = 0; i < zu; i++) {
        int st = i * glen;
        int end = min(st + glen, len);
        int j = 0;
        for (int k = st; k < end; k++) {
            tmp[i * glen + j] = s[k];
            j++;
        }
        for (; j < glen; j++) tmp[i * glen + j] = '0';
    }
    for (int i = 0; i < zu / 2; i++) {
        for (int j = 0; j < glen; j++) {
            char t = tmp[i * glen + j];
            tmp[i * glen + j] = tmp[(zu - 1 - i) * glen + j];
            tmp[(zu - 1 - i) * glen + j] = t;
        }
    }
    int qiandao0 = 1;
    for (int i = 0; i < zu * glen; i++) {
        if (qiandao0 && tmp[i] == '0') continue;
        qiandao0 = 0;
        cout << tmp[i];
    }
    if (qiandao0) cout << '0';
    return 0;
}