#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 7;
const int MAXM = 200000 + 7;
int fa[MAXN], n, m;
struct Edge{
	int u, v, w;
}e[MAXM];
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
int find(int x){
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
void merge(int u, int v){
	int fu = find(u), fv = find(v);
	if(fu != fv) fa[fu] = fv;
}
int ans = 0, cnt = 0;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1;i <= m;i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		ans += w, cnt++;
		merge(u, v);
	}
	if(cnt != n - 1){
		cout << "orz\n";
	}
	else cout << ans << '\n';
	return 0;
}