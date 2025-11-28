#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct state{
    int p, c;
    bool operator<(const state &t) const { return p < t.p; }
};
struct truck{
    int a, b;
    bool operator<(const truck &t) const { return a - b > t.a - t.b; }
};
state s[N];
truck t[N];
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 1;i <= n;i++) cin >> s[i].p >> s[i].c;
    for(int i = 1;i <= m;i++) cin >> t[i].a >> t[i].b;
    sort(s + 1, s + n + 1);
    sort(t + 1, t + m + 1);
    ll ans = 0;
    for(int i = 1, l = 1;i <= m && t[i].a > t[i].b;i++){
        int p = s[l].p, a = t[i].a, b = t[i].b;
        ans += 2ll * (a - b) * p + 2ll * b * x;
        if(--s[l].c == 0) l++;
    }
    for(int j = m, r = n;j >= 1 && t[j].a <= t[j].b;j--){
        int p = s[r].p, a = t[j].a, b = t[j]. b;
        ans += 2ll * (a - b) * p + 2ll * b * x;
        if(--s[r].c == 0) r--;
    }
    cout << ans << endl;
    return 0;
}