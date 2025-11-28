#include<bits/stdc++.h>
using namespace std;
const int N = 60 + 5;
long long f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3;i <= n;i++){
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    cout << f[n];
    return 0;
}