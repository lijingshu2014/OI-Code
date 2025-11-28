#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	if (a > b) swap(a, b); 
	if (a == b) {
		cout << min(n, m) / a;
		return 0;
	}
	long long l = 0, r = 1e9;
	while (l < r) {
		long long mid = (l + r + 1) / 2;
		if (n < a * mid || m < a * mid || (n - a * mid) / (b - a) + (m - a * mid) / (b - a) < mid)r = mid - 1;
		else l = mid;
	}
	cout << l;
	return 0;
}