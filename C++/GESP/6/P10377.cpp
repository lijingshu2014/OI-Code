#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n, ans = 1e9, id[N], a[N], b[N];
bool vis[N];
void dfs(int x) {
	if (x > n) {
		int cnt = n;
		for (int i = 2; i <= n; i++) cnt += max(a[id[i]], b[id[i - 1]]);
		ans = min(ans, cnt);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			id[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dfs(1);
	cout << ans;
	return 0;
}