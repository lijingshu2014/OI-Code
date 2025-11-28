#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[150], pre[150];
signed main() {
    int p;
    string s;
	cin >> p >> s;
	int n = s.size(), num = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		num = s[i] - '0';
		for (int j = 0; j < p; j++){
            pre[j] = f[j];
            f[j] = 0;
        }
		for (int j = 0; j < p; j++){
            f[(j * 10 + num) % p] += pre[j];
        }
		f[num % p]++;
		ans += f[0];
	}
	cout << ans;
	return 0;
}