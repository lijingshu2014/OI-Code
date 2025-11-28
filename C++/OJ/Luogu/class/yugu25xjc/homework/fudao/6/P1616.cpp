#include<bits/stdc++.h>
using namespace std;
const int M = 1e4 + 5;
const int L = 1e7 + 5;
typedef long long ll;
int time_cost[M], value[M];
ll f[L];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, m;
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> time_cost[i] >> value[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = time_cost[i];j <= t;j++){
            f[j] = max(f[j], f[j - time_cost[i]] + value[i]);
        }
    }
    cout << f[t];
    return 0;
}