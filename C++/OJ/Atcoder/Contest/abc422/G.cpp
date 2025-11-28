#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll fact[300005], inv_fact[300005];
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
ll comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
ll solve1(int N, int A, int B, int C) {
    ll ans = 0;
    int MAXX = N / A;
    for (int x = 0; x <= MAXX; x++) {
        int rem = N - A * x;
        if (rem < 0) continue;
        int MAXY = rem / B;
        for (int y = 0; y <= MAXY; y++) {
            int rem2 = rem - B * y;
            if (rem2 >= 0 && rem2 % C == 0) {
                ans++;
                ans %= MOD;
            }
        }
    }
    return ans;
}
ll solve2(int N, int A, int B, int C) {
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int a = 0; a <= N; a += A) {
        for (int b = 0; b <= N - a; b += B) {
            int c = N - a - b;
            if (c >= 0 && c % C == 0) {
                ans = (ans + comb(N, a) * comb(N - a, b) % MOD) % MOD;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i < 300005; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[300005 - 1] = power(fact[300005 - 1], MOD - 2);
    for (int i = 300005 - 2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    cout << solve1(N, A, B, C) << endl;
    cout << solve2(N, A, B, C) << endl;
    return 0;
}