#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N];
int a[N], op[N];
void dfs(int u){
    a[u] ^= op[u];
    for(int v:e[u]){
        op[v] ^= op[u];
        dfs(v);
    }
}
int main(){
    int n;
    cin >> n;
    for(int v = 2;v <= n;v++){
        int u;
        cin >> u;
        e[u].push_back(v);
    }
    for(int u = 1;u <= n;u++){
        scanf("%1d", &a[u]);
    }
    int q;
    cin >> q;
    while(q--){
        int u;
        cin >> u;
        op[u] ^= 1;
    }
    dfs(1);
    for(int i = 1;i <= n;i++){
        cout << a[i];
    }
    cout << endl;
    return 0;
}