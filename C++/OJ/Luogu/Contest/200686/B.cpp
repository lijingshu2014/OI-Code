#include<bits/stdc++.h>
using namespace std;
struct node {
	int id, g, s, b;
} medal[200005];
bool cmpg(node a, node b) {
	return a.g > b.g;
}
bool cmps(node a, node b) {
	return a.s > b.s;
}
bool cmpb(node a, node b) {
	return a.b > b.b;
}
int n;
int main() {
//	freopen("medal.in", "r", stdin);
//	freopen("medal.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> medal[i].g >> medal[i].s >> medal[i].b;
		medal[i].id = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		int rg = 1, rs = 1, rb = 1;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (cmpg(medal[j], medal[i])) rg++;
				if (cmps(medal[j], medal[i])) rs++;
				if (cmpb(medal[j], medal[i])) rb++;
			}
		}
		cout << min({rg, rs, rb}) << endl;
	}
	return 0;
}