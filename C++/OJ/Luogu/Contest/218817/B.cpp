#include <bits/stdc++.h>
using namespace std;
int minx(int a, int b) {
	int ans = 1e9;
	for (int x = 0; x <= 5000; x++) {
		int ta = a, tb = b;
		int cnt = 0;
		for (int i = 0; i < x; i++) {
			int tta = ta;
			ta *= 2;
			int ttb1 = tb;
			ttb1--;
			int ttb2 = tb;
			ttb2++;

			int cnt1 = 1e9, cnt3 = 1e9;
			if (ta == ttb1) {
				cnt1 = cnt + 1;
			} else if (ta == ttb2) {
				cnt3 = cnt + 1;
			}
			if (cnt1 < ans) {
				cnt = cnt1;
				tb = ttb1;
			} else if (cnt3 < ans) {
				cnt = cnt3;
				tb = ttb2;
			} else {
				ta = tta;
				tb = ttb1;
			}
		}
		if (ta == tb) {
			ans = min(ans, cnt);
		}
	}
	return ans;
}
int a, b;
int main() {
	cin >> a >> b;
	cout << minx(a, b);
	return 0;
}