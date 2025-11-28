#include<bits/stdc++.h>
using namespace std;
int n, m, s;
vector<pair<int, int>> G[100005];
int dis[100005];
bool vis[100005];
void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(-0, s));
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto [v, w] : G[x]) {
			if (dis[v] > dis[x] + w) {
				dis[v] = dis[x] + w;
				pq.push(make_pair(-dis[v], v));
			}
		}
	}
}
int main() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		G[x].push_back(make_pair(y, z));
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		if (i == n) cout << dis[i] << '\n';
		else cout << dis[i] << ' ';
	}
	return 0;
}