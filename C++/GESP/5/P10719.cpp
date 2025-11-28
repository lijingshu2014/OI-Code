#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m, q;
int a[N][N], s[N][N];
int main(){
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            scanf("%1d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = i;k <= n;k++){
                for(int l = j;l <= m;l++){
                    int x = s[k][l] - s[k][j - 1] - s[i - 1][l] + s[i - 1][j - 1];
                    if(x >= q){
                        ans = min(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }
    cout << (ans == INT_MAX ? 0 : ans) << endl;
    return 0;
}