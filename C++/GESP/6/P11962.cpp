#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int num[N], vis[N];
vector<int> g[N];
void dfs(int x, int walk){
    if(walk % 2 == 0){
        num[2]++;
        vis[x] = 2;
    }else{
        num[1]++;
        vis[x] = 1;
    }
    for(int i = 0;i < g[x].size();i++){
        if(!vis[g[x][i]]){
            dfs(g[x][i], walk + 1);
        }
    }
}
void add(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    dfs(1, 0);
    for(int i = 1;i <= n;i++){
        cout << num[vis[i]] << " ";
    }
    return 0;
}