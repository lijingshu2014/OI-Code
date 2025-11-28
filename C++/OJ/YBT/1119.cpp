#include<bits/stdc++.h>
using namespace std;
int a[6][7], m, n;
int main(){
	for(int i = 1;i <= 5;i++){
		for(int j = 1;j <= 5;j++) cin >> a[i][j];
	}
	cin >> m >> n;
	for(int i = 1;i <= 5;i++){
		a[0][i] = a[m][i];
	}
	for(int i = 1;i <= 5;i++){
		a[m][i] = a[n][i];
	}
	for(int i = 1;i <= 5;i++){
		a[n][i] = a[0][i];
	}
	for(int i = 1;i <= 5;i++){
		for(int j = 1;j <= 5;j++) cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}