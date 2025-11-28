#include <bits/stdc++.h>
using namespace std;
struct node {
	string sex;
	double high;
} a[41];
bool cmp(node a, node b) {
	if (a.sex == "male" && b.sex == "male") return a.high < b.high;
	else if (a.sex == "female" && b.sex == "female") return a.high > b.high;
	return a.sex > b.sex;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].sex >> a[i].high;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) printf("%.2lf ", a[i].high);
	return 0;
}