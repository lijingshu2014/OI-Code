#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int main() {
    // freopen("trip.in", "r", stdin);
    // freopen("trip.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        unordered_map<int, int> cnt;
        int sum = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (cnt.find(sum) != cnt.end()) ans = max(ans, cnt[sum]);
            cnt[sum]++;
        }
        cout << ans << endl;
    }
    return 0;
}