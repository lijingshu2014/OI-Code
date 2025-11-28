#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll p, q;
        cin >> p >> q;
        ll g = gcd(p, q);
        ll g2 = gcd(p / g, 180 * (q / g));
        ll ans = (180 * (q / g)) / g2;
        cout << ans - 1 << endl;
    }
    return 0;
}