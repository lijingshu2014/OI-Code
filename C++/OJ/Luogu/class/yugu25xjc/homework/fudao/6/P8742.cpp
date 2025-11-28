#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
const int M = 1e5 + 5;
int w[N];
bool dp[N][M];
int abs(int x){
    if(x < 0) return -x;
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int total_weight = 0;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        total_weight += w[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= total_weight; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = 0;j <= total_weight; j++) if(dp[i - 1][j]){
            if(j + w[i] <= total_weight){
                dp[i][j + w[i]] = 1;
            }
            dp[i][abs(j - w[i])] = 1;
        }
    }
    int cnt = 0;
    for(int j = 1;j <= total_weight; j++){
        if(dp[n][j]) ++cnt;
    }
    cout << cnt;
    return 0;
}