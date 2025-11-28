#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, a, b, c, x[N], y[N], z[N], all[N], ans;
int main() {
    cin >> n >> a;
    for (int i = 1; i <= a; i++) cin >> x[i];
    cin >> b;
    for (int i = 1; i <= b; i++) cin >> y[i];
    cin >> c;
    for (int i = 1; i <= c; i++) cin >> z[i];
    for (int i = 1; i <= a; i++) all[x[i]]++;
    for (int i = 1; i <= b; i++) all[y[i]]++;
    for (int i = 1; i <= c; i++) all[z[i]]++;
	for (int i = 1; i <= n; i++) {
        if (all[i] == 0 || all[i] > 1) ans++;
    }
    cout << ans;
    return 0;
}