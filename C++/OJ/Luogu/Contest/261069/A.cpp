#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], b[MAXN];
int pos[MAXN];
int dp[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = pos[a[i]];
        dp[i] = 1;
        if (i > 1 && pos[a[i - 1]] < cur) {
            dp[i] = dp[i - 1] + 1;
        }
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}