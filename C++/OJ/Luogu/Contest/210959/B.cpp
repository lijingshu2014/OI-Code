#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, a[N];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int k = 0;
		bool flag = 1;
		while (n > 0 && flag == 1) {
			flag = 0;
			int i = 0;
			while (i < n) {
				int j = i;
				while (j < n && a[j] == a[i]) j++;
				if (j - i > 1) {
					for (int p = i; p + (j - i) < n; p++) {
						a[p] = a[p + (j - i)];
					}
					n -= (j - i);
					flag = 1;
					k++;
					i = 0;
					continue;
				}
				i++;
			}
			if (flag == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						swap(a[i], a[j]);
						int ci = 0;
						while (ci < n) {
							int cj = ci;
							while (cj < n && a[cj] == a[ci]) cj++;
							if (cj - ci > 1) {
								flag = 1;
								k++;
								break;
							}
							ci++;
						}
						if (flag == 1) break;
						swap(a[i], a[j]);
					}
					if (flag == 1) break;
				}
			}
		}
		cout << k << endl;
	}
	return 0;
}