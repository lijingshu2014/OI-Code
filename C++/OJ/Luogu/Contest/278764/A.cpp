#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;
const ll INF = 1e18;
ll a[MAXN];
bool vis[MAXN];
ll edge_weight(int u, int v) {
    return (a[u] ^ a[v]) + (a[u] | a[v]) + (a[u] & a[v]);
}
void dijkstra(int n, int s, int t) {
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (u != v && !vis[v]) {
                ll w = edge_weight(u - 1, v - 1);
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    cout << dist[t] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, s, t;
        cin >> n >> s >> t;
        for (int i = 0; i < n; i++) cin >> a[i];
        fill(vis, vis + n + 1, 0);
        dijkstra(n, s, t);
    }
    return 0;
}