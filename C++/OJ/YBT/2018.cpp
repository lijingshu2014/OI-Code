#include<bits/stdc++.h>
using namespace std;
int n, sum1, sum2;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i += 2) sum1 += i;
	for(int i = 2;i <= n;i += 2) sum2 += i;
	cout << sum2 << ' ' << sum1;
	return 0;
}