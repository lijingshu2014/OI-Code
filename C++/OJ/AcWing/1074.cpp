#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int father) {
	for (int i = h[u]; ~i; i = ne[i]) {
		if (e[i] == father) continue;
		dfs(e[i], u);
		for (int j = m; j; j--){
			for (int k = 0; k + 1 <= j; k++){
				f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
            }
        }
	}
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	dfs(1, -1);
	printf("%d\n", f[1][m]);
	return 0;
}