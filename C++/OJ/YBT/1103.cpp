#include<bits/stdc++.h>
using namespace std;
int a[15], k, ans; 
int main(){
	for(int i = 1;i <= 10;i++) cin >> a[i];
	cin >> k;
	int t = k + 30;
	for(int i = 1;i <= 10;i++){
		if(t >= a[i]) ans++;
	}
	cout << ans;
	return 0;
}