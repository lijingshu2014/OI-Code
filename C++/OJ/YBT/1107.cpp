#include<bits/stdc++.h>
using namespace std;
int L, M;
bool a[10005];
int main(){
	cin >> L >> M;
	for (int i = 1; i <= M; i++){
		int x, y;
		cin >> x >> y;
		for (int j = x; j <= y; j++) a[j] = 1;
	}
	int ans = 0;
	for (int i = 0; i <= L; i++){
		if (a[i] == 0) ans++;
	}
	cout << ans;
	return 0;
}