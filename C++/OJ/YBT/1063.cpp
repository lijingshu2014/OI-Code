#include<bits/stdc++.h>
using namespace std;
int n, maxn = 0, minn = 1001;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		maxn = max(a, maxn);
		minn = min(a, minn);
	}
	cout << maxn - minn;
	return 0;
}