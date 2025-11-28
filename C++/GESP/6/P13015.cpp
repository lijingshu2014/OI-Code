#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int n, a[N], f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        f[i] = 0;
        for(int k = 1;k <= i;k++){
            f[i] = max(f[i], f[i - k] + a[k]);
        }
    }
    cout << f[n];
    return 0;
}