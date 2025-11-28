#include <bits/stdc++.h>
using namespace std;
int y[15], s[15];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> y[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (y[i] == s[i]) {
            ans++;
            continue;
        }
        int dy = y[i + 1] - y[i];
        int ds = s[i + 1] - s[i];
        int d = ds - dy;
        if (d == 0) {
            if (y[i] - s[i] == 0) ans++;
            continue;
        }
        int n = (s[i] - y[i]);
        if (d < 0) {
            d = -d;
            n = -n;
        }
        if (n >= 0 && n <= d) ans++;
    }
    cout << ans;
    return 0;
}