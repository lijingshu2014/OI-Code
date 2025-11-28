#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int T, M;
int time_cost[N], value[N];
// int f[N][N];
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T >> M;
    for(int i = 1; i <= M; i++){
        cin >> time_cost[i] >> value[i];
    }
    // for(int i = 1; i <= M; i++){
    //     for(int j = 0;j <= T;j++){
    //         f[i][j] = f[i - 1][j];
    //         if(j >= time_cost[i]){
    //             f[i][j] = max(f[i][j], f[i - 1][j - time_cost[i]] + value[i]);
    //         }
    //     }
    // }
    // cout << f[M][T];
    for(int i = 1; i <= M; i++){
        for(int j = T;j >= 0;j--){
            if(j >= time_cost[i]){
                f[j] = max(f[j], f[j - time_cost[i]] + value[i]);
            }
        }
    }
    cout << f[T];
    return 0;
}