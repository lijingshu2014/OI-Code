#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll a = (r + l) % 9;
        ll b = (r - l + 1) % 9;
        if(a >= 0) a = a;
        else a = a + 9;
        if(b >= 0) b = b;
        else b = b + 9;
        ll ans = a * b * 5 % 9;
        cout << ans << endl;
    }
    return 0;
}