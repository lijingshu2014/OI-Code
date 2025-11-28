#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int x, int k) {
    return x ^ (x + (1 << k));
}
int T, n, k;
signed main() {
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 0; i <= n; i++) ans += f(i, k);
        cout << ans << endl;
    }
    return 0;
}