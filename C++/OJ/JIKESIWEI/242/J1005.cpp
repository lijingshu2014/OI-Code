#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a, n, p;
	cin >> a >> n >> p;
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
        ans = ans * (a % p) % p;
    }
	cout << ans;
	return 0;
}