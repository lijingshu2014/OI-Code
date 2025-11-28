#include<bits/stdc++.h>
using namespace std;
int t;
long long n, k;
int main(){
	//freopen("division.in", "r", stdin);
	//freopen("division.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k == 0) cout << 1 << endl;
		else{
			long long cnt = 0;
			for(long long q = 1;q <= n;q++){
				long long r = n % q;
				if(k * q + r == n) cnt++;
			} 
			cout << cnt << endl;
		}
	}
	return 0;
}