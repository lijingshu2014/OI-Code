#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long func(string t) {
	int n = t.size();
	long long res = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		int l = i / 2, r = l + i % 2;
		while (l >= 0 && r < n && t[l] == t[r]) {
			res = (res + 1) % MOD;
			l--;
			r++;
		}
	}
	return res;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s, t;
		cin >> s;
		for (int i = 0; i < k; i++) t += s;
		cout << func(t) << endl;
	}
	return 0;
}