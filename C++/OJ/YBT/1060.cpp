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
	sum /= n;
	printf("%.4lf", sum);
	return 0;
}