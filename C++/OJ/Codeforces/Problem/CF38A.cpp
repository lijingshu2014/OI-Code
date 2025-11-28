#include<bits/stdc++.h>
using namespace std;
int d[105];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)  cin >> d[i];
	int a, b, ans = 0;
	cin >> a >> b;
	for(int i = a; i < b; i++) ans += d[i];
	cout << ans;
	return 0;
}