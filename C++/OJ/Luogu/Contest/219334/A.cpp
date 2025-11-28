#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005]; 
signed main() {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if ((n - 2) * s % (2 * n) != 0) {
        cout << -1;
        return 0;
    }
    int x = (n - 2) * s / (2 * n);
    int d = s - x, s_p = 0, s_n = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = n * a[i] - d;
        if (tmp > 0) s_p += tmp;
        else s_n -= tmp;
    }
    if (s_p != s_n) cout << -1;
    else cout << s_p / n;
    return 0;
}