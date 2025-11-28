#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15];
int main(){
    int k;
    cin >> k;
    for(int i = 1;i <= k;i++) cin >> a[i];
    ll ans = 1;
    for(int i = 1;i <= k;i++) ans *= a[i];
    cout << ans;
    return 0;
}