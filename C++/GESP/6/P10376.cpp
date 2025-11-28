#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int f[200005];
int main() {
    int n, a, b, c;
	cin >> n >> a >> b >> c;
	for (int i = 0; i <= n; i++) {
		if (i <= c){
            f[i] = 1;
        }
		else{
            int tmp1 = max(i - a, 0);
            int tmp2 = max(i - b, 0);
            f[i] = (f[tmp1] + f[tmp2]) % mod;
        }
	}
	cout << f[n];
	return 0;
}