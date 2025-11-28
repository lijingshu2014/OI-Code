#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans = -1e9;
int vis[100005];
struct node {
	int v, w;
};
vector<node> e[100005];
void dfs(int x, int val) {
	if (vis[x]) return;
	vis[x] = 1;
	for (node i : e[x]) dfs(i.v, val + i.w);
	ans = max(ans, val);
}
signed main() {
    int n;
	cin >> n;
    int sum = 0;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
		sum += w;
	}
	dfs(1, 0);
	cout << sum * 2 - ans;
	return 0;
}