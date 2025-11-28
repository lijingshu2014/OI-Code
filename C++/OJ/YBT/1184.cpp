#include<iostream>
using namespace std;
int a[105];
bool vis[1005];
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		vis[a[i]] = 1;
	}
	int cnt = 0;
	for(int i = 1;i <= 1000;i++){
		if(vis[i] == 1) cnt++;
	}
	cout << cnt << endl;
	for(int i = 1;i <= 1000;i++){
		if(vis[i] == 1) cout << i << ' ';
	}
	return 0;
}