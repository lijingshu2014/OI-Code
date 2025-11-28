#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<pair<ll, int>> fac;
    for(int i = 2;1ll * i * i <= n;i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            fac.push_back(make_pair(i, cnt));
        }
    }
    if(n != 1) fac.push_back(make_pair(n, 1));
    for(int i = 0;i < fac.size();i++){
        ll x = fac[i].first;
        int y = fac[i].second;
        if(i != 0) printf(" * ");
        printf("%lld", x);
        if(y != 1) printf("^%d", y);
    }
    return 0;
}
// 1 * 2 * 3