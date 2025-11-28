#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    int ans = 0;
    for(int i = 2;1ll * i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            int k = 0;
            while(cnt >= 0){
                k++;
                cnt -= k;
            }
            ans += k - 1;
        }
    }
    if(n > 1) ans++;
    cout << ans;
    return 0;
}