#include<iostream>
#include<cstring>
using namespace std;
int n, q, m, ans, f[300], cnt[300];
void dfs(int x){
	cnt[x]++;
	if(f[x] != x){
		dfs(f[x]);
	}
}
int main(){
	cin >> n;
	for(int i = 1;i < n;i++) cin >> f[i];
	cin >> q;
	for(int i = 1;i <= q;i++){
		memset(cnt, 0, sizeof(cnt));
		ans = 0;
		cin >> m;
		for(int j = 1;j <= m;j++){
			int x;  
			cin >> x;
			dfs(x);
		}
		for(int j = 1;j < n;j++){
			if(cnt[j] == m){
				ans = j;
			}
		}
		cout << ans << endl;
	}
	return 0;
}