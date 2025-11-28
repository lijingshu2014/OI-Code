#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
int a[N], b[N], cnt[N];
ll sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (1ll * n * n < k) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    int m = 0;
    for (int i = 0; i < n; ) {
        b[m] = a[i];
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        cnt[m] = j - i;
        m++;
        i = j;
    }
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    sum[0] = 0;
    for (int i = 0; i < m; i++) sum[i + 1] = sum[i] + cnt[i];
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            ll cnt_x = sum[j + 1] - sum[i];
            if (cnt_x == 0) continue;
            ll min_cnt_y = (k + cnt_x - 1) / cnt_x;
            if (min_cnt_y > sum[m]) continue;
            int p = 0, q = m - 1;
            while (p <= q && sum[q + 1] - sum[p] < min_cnt_y) {
                if (p > 0) p--;
                else if (q < m - 1) q++;
                else break;
            }
            while (p <= q) {
                ll cur = sum[q + 1] - sum[p];
                if (cur >= min_cnt_y) {
                    ll res = 1ll * (b[j] - b[i]) * (b[q] - b[p]);
                    ans = max(ans, res);
                    if (p + 1 <= q) {
                        ll res1 = 1ll * (b[j] - b[i]) * (b[q] - b[p + 1]);
                        ll res2 = 1ll * (b[j] - b[i]) * (b[q - 1] - b[p]);
                        if (res1 > res2) p++;
                        else q--;
                    } else break;
                    
                } else break; 
            }
        }
    }
    cout << ans;
    return 0;
}