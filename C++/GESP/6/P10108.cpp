#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 105, inf = 0x3f3f3f3f;
int a[M], b[N], f[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	memset(f, -inf, sizeof(f));
	f[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i - a[j] >= 0) {
				f[i] = max(f[i], f[i - a[j]] + b[i - a[j]]);
			}
		}
	}
	int ans = -inf;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i + a[j] >= n) {
				ans = max(ans, f[i] + b[i]);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}