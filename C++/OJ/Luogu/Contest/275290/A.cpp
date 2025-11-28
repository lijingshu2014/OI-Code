#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        cout << b - a << endl;
        return 0;
    }
    ll cur = a;
    int ans = 0;
    while (cur < b) {
        if (cur == 0) {
            cur += k;
            ans++;
        } else {
            ll add = cur + k;
            ll mul = cur * k;
            if (mul < b && mul > add) {
                cur = mul;
                ans++;
            } else {
                ll need = b - cur;
                ans += (need + k - 1) / k;
                cur = b;
            }
        }
    }
    cout << ans;
    return 0;
}