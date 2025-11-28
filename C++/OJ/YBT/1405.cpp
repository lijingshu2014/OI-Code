#include<bits/stdc++.h>
using namespace std;
bool isprime(int x){
	if(x < 2) return 0;
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0) return 0;
	}
	return 1;
}
int s;
int main(){
	cin >> s;
	int maxn = -1e9;
	for(int i = 2;i <= s;i++){
		int ans;
		for(int j = 2;j <= s;j++){
			if(isprime(i) && isprime(j)){
				if(i + j == s){
					ans = i * j;
				}
			}
		}
		maxn = max(ans, maxn);
	}
	cout << maxn;
	return 0;
}