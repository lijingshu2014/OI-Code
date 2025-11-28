#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
    int ans = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		ans *= a / gcd(ans, a);
	}
	cout << ans;
	return 0;
}