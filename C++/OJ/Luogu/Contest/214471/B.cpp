#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 20 + 5;
const int MAXM = 100005;
string S[MAXN], T[MAXN];
ll s_id[MAXM], t_id[MAXM];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        ll ans = 1;
        for (int i = 1; i <= m; i++) ans = ans * i % MOD;
        for (int i = 0; i < m; i++) ans = ans * 2 % MOD;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> S[i];
    for (int i = 0; i < n; i++) cin >> T[i];
    if (n == 1) {
        ll ans = 1;
        for (int i = 1; i <= m; i++) ans = ans * i % MOD;
        for (int i = 0; i < m; i++) ans = ans * 2 % MOD;
        cout << ans << endl;
        return 0;
    }
    for (int j = 0; j < m; j++) {
        ll id = 0;
        for (int i = 1; i < n; i++) {
            id = (id << 1) | (S[i][j] ^ S[0][j]);
        }
        s_id[j] = id;
    }
    for (int j = 0; j < m; j++) {
        ll id = 0;
        for (int i = 1; i < n; i++) {
            id = (id << 1) | (T[i][j] ^ T[0][j]);
        }
        t_id[j] = id;
    }
    unordered_map<ll, int> s_cnt, t_cnt;
    for (int j = 0; j < m; j++) {
        s_cnt[s_id[j]]++;
        t_cnt[t_id[j]]++;
    }
    for (auto& [id, cnt] : s_cnt) {
        if (t_cnt[id] != cnt) {
            cout << "0" << endl;
            return 0;
        }
    }
    for (auto& [id, cnt] : t_cnt) {
        if (s_cnt[id] != cnt) {
            cout << "0" << endl;
            return 0;
        }
    }
    ll ans = 1;
    for (auto& [id, cnt] : s_cnt) {
        for (int i = 2; i <= cnt; i++) {
            ans = ans * i % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}