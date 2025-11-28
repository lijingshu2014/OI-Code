#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 5;
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        f[i] = INF;
    }
    f[0] = 0;
    for(int i = 1; i * i <= n; i++){
        int weight = i * i;
        for(int j = weight; j <= n; j++){
            f[j] = min(f[j], f[j - weight] + 1);
        }
    }
    cout << f[n];
    return 0;
}