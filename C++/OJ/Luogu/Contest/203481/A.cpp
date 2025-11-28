#include<bits/stdc++.h>
using namespace std;
int n, a[200005], b[200005];
int maxx, ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > maxx) maxx = a[i];
		ans += max(b[i], a[i] - b[i]);
	}
	cout << ans;
	return 0;
}