#include<bits/stdc++.h>
using namespace std;
double f(double x, int n) {
	if (n == 1) return x / (1 + x);
	return x / (n + f(x, n - 1));
}
int main() {
	double x;
    int n;
	cin >> x >> n;
	printf("%.2f", f(x, n));
	return 0;
}