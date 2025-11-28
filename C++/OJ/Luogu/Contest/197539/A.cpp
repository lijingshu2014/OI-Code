#include <iostream>
using namespace std;
int n, p[100005];
bool vis[1000005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (vis[p[i]]) continue;
        if (p[i]!= i + 1) {
            int j = i + 1;
            while (j < n && (!vis[j] && p[j]!= i + 1)) {
                j++;
            }
            if (j < n) {
                ans += j - i;
                for (int k = j; k > i; k--) {
                    swap(p[k], p[k - 1]);
                }
            } else {
                vis[p[i]] = 1;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}