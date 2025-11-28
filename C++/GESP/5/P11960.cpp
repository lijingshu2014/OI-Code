#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005], b[200005], c[200005];
int main() {
    int n;
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n * 2; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n * 2; i++) {
		cin >> b[i];
		c[i] = b[i] - a[i];
	}
	sort(c + 1, c + 2 * n + 1);
	for (int i = n * 2; i > n; i--) {
		sum += c[i];
	}
	cout << sum;
	return 0;
}