#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 7;
int fa[MAXN];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    fa[fx] = fy;
}
int main(){
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1, x, y; i <= m; i++){
        cin >> x >> y;
        merge(x, y);
    }
    while(p--){
        int x, y;
        cin >> x >> y;
        int fx = find(x), fy = find(y);
        if(fx == fy) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}