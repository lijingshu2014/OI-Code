#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[100005];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[i] = a * a;
    }
    sort(s, s + n);
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans += s[i + 1] - s[i];
    }
    int cur = ans;
    for (int i = 1; i <= n - m; i++) {
        cur = cur - (s[i] - s[i - 1]) + (s[i + m - 1] - s[i + m - 2]);
        ans = min(cur, ans);
    }
    cout << ans;
    return 0;
}