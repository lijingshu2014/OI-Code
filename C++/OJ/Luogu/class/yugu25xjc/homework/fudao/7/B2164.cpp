#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int mod = 1e9 + 7;
int c[N][N];
int main(){
    int n, m;
    cin >> n >> m;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++){
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    cout << c[n][m] << endl;
    // for(int i = 0;i <= n;i++){
    //     for(int j = 0;j <= i;j++){
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}