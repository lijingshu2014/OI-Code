#include<bits/stdc++.h>
using namespace std;
int n, a[1005], maxn = -1e9;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		maxn = max(a[i], maxn);
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == maxn){
			cout << i;
			break;
		}
	}
	return 0;
}