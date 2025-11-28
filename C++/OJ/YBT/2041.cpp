#include<bits/stdc++.h>
using namespace std;
int n, a[22][22];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j || j == n + 1 - i) a[i][j] += 10;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}