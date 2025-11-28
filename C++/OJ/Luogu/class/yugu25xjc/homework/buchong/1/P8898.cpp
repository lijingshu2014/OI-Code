#include<bits/stdc++.h>
using namespace std;
int res[100005];
bool vis[100005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		memset(vis, 0, sizeof(vis));
		memset(res, 0, sizeof(res));
		cin >> n >> k >> s;
		int cnt = 0, h = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'H') {
				if (abs(i - h) > k || h == -1) {
					for (int j = min(i + k, n - 1); j >= max(i - k, 0); j--) {
						if (!vis[j]) {
							res[j] = 1;
							vis[j] = 1;
							h = j;
							cnt++;
							break;
						}
					}
				}
			}
			int g = -1;
			if (s[i] == 'G') {
				if (abs(i - g) > k || g == -1) {
					for (int j = min(i + k, n - 1); j >= max(i - k, 0); j--) {
						if (!vis[j]) {
							res[j] = 2;
							vis[j] = 1;
							g = j;
							cnt++;
							break;
						}
					}
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			if (res[i] == 0) cout << '.';
			if (res[i] == 1) cout << 'H';
			if (res[i] == 2) cout << 'G';
		}
		cout << endl;
	}
	return 0;
}