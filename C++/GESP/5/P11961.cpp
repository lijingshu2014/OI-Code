#include <bits/stdc++.h>
#define int long long
using namespace std;
int power(int a, int b, int p) {
    int res = 1;
    a = a % p;
    while (b > 0) {
        if (b & 1) { 
            res = (res * a) % p;
        }
        a = (a * a) % p; 
        b >>= 1; 
    }
    return res;
}
int Count(int n, int res[]) {
    int cnt = 0;
    if (n % 2 == 0) {
        res[cnt++] = 2;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            res[cnt++] = i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) res[cnt++] = n;
    return cnt;
}
int res[100];
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int a, p;
        cin >> a >> p;
        int m = p - 1;
        if (power(a, m, p) != 1) {
            cout << "No" << endl;
            continue;
        }
        memset(res, 0, sizeof(res));
        int cnt = Count(m, res);
        bool flag = 1;
        for (int i = 0; i < cnt; i++) {
            int q = res[i];
            if (power(a, m / q, p) == 1) {
                flag = 0;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}