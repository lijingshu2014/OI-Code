#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int T, n, m, a[10000005], dp[2000][2000];
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = i - 1; k >= 0; k--) {
                    bool flag = 1;
                    for (int l = k + 1; l < i; l++) {
                        if (a[l] <= a[l - 1]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) dp[i][j] = (dp[i][j] + dp[k][j - 1]) % mod;
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}