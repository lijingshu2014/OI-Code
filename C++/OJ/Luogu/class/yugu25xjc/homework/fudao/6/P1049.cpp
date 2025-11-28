#include<bits/stdc++.h>
using namespace std;
int v[25];
int f[20005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int V, n;
    cin >> V >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = V;j >= v[i];j--){
            if(f[j - v[i]]) f[j] = 1;
        }
    }
    int max_use = V + 1;
    for(int i = V;i >= 0;i--){
        if(f[i]){
            max_use = i;
            break;
        }
    }
    int ans = V - max_use;
    cout << ans;
    return 0;
}