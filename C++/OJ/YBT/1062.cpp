#include<bits/stdc++.h>
using namespace std;
int n, maxn = -1;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		maxn = max(a, maxn);
	}
	cout << maxn;
	return 0;
}