#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e4 + 5;
int c[MAXN], a[MAXN];
int main () {
	int n, m;
	cin >> n >> m;
    int Max = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]);
	}
    int ans = Max;
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		if (n == 1 || c[i] > 0) ans += c[i];
	}
	cout << ans;
	return 0;
}