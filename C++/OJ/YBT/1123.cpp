#include<bits/stdc++.h>
using namespace std;
int m, n, a[105][105], b[105][105];
int main(){
	cin >> m >> n;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++) scanf("%d", &b[i][j]);
	}
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j] == b[i][j]) cnt++;
		}
	}
	double ans = (double)cnt / (double)(n * m) * 100.0;
	printf("%.2lf", ans);
	return 0;
}