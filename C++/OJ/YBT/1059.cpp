#include<bits/stdc++.h>
using namespace std;
int n;
double sum = 0;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		double a;
		cin >> a;
		sum += a;
	}
	sum /= n;
	printf("%.2lf", sum);
	return 0;
}