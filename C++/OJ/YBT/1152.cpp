#include<bits/stdc++.h>
using namespace std;
float Max(int a, int b, int c){
	return max(a, max(b, c));
}
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	float m;
	m = Max(a, b, c) / (Max(a + b, b, c) * Max(a, b, b + c));
	printf("%.3f", m);
	return 0;
}