#include<bits/stdc++.h>
using namespace std;
struct node {
	int id, fenshu;
} person[10005];
int cmp(node p1,node p2) {
	if(p1.fenshu > p2.fenshu) return 1;
	else if(p1.fenshu == p2.fenshu) {
		if(p1.id < p2.id) return 1;
		else return 0;
	} else return 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	m = floor(m * 1.5);
	for(int i = 0; i < n; i++) {
		cin >> person[i].id >> person[i].fenshu;
	}
	sort(person, person + n, cmp);
	int xian = person[m - 1].fenshu;
	int cnt = m;
	for(int i = m; i < n; i++) {
		if(person[i].fenshu == xian) cnt += 1;
		else if(person[i].fenshu < xian) break;
	}
	cout << xian << ' ' << cnt << endl;
	for(int i = 0; i < cnt; i++) {
		cout << person[i].id << ' ' << person[i].fenshu << endl;
	}
	return 0;
}