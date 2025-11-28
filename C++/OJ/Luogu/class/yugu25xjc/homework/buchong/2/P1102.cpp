#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N];
long long ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; j++) {
		while (a[i] - a[j] < m && i <= n) i++;
		if (i > n) break;
		if (a[i] - a[j] > m)
			continue;
		int x = 1, y = 1;
		while (a[i + 1] == a[i]) x++, i++;
		while (a[j + 1] == a[j]) y++, j++;
		ans += 1ll * x * y;
	}
	cout << ans;
}