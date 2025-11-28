#include<bits/stdc++.h>
using namespace std;
int n;
double sum;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		double a;
		cin >> a;
		sum += a;
	}
	cout << sum << ' ';
	sum /= n;
	printf("%.5lf", sum);
	return 0;
}