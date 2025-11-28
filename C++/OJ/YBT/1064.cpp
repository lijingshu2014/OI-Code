#include<bits/stdc++.h>
using namespace std;
int n, sum1, sum2, sum3;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a, b, c;
		cin >> a >> b >> c;
		sum1 += a;
		sum2 += b;
		sum3 += c;
	}
	cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum1 + sum2 + sum3;
	return 0;
}