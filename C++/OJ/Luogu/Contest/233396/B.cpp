#include <bits/stdc++.h>
using namespace std;
int d[1000000];
long long s[1000001];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d + n);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (long long)d[i - 1] * i;
    }
    for (int i = 0; i < q; i++) {
        long long t;
        cin >> t;
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (s[m] <= t) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}