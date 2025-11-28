#include<bits/stdc++.h>
using namespace std;
int n, res[1000005];
queue<int> q;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) q.push(i);
	for (int i = 1; i <= n; i++) {
		q.push(q.front());
		q.pop();
		res[q.front()] = i;
		q.pop();
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	return 0;
}