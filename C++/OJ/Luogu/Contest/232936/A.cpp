#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int power(int a, int b) {
    int res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1) { 
            res = (res * a) % mod;
        }
        a = (a * a) % mod; 
        b >>= 1; 
    }
    return res;
}
int niyuan(int a) {
    return power(a, mod - 2);
}
signed main() {
    int n;
    cin >> n;
    int q = n / mod, r = n % mod;
    int tmp1 = (((q % mod) * ((q - 1) % mod)) % mod) * niyuan(2) % mod;
    tmp1 = tmp1 * (mod % mod) % mod;
    int tmp2 = ((q % mod) * ((r + 1) % mod)) % mod;
    int ans = (tmp1 + tmp2) % mod;
    if (ans < 0) ans += mod;
    cout << ans;
    return 0;
}