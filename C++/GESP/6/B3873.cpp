#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, inf = 0x3f3f3f3f;
int f[N];
int main(){
    int n, m;
    cin >> n >> m;
    memset(f, inf, sizeof(f));
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        int c, l;
        cin >> c >> l;
        l = min(m, l);
        for(int j = 2 * m;j >= l;j--){
            f[j] = min(f[j], f[j - l] + c);
        }
    }
    int ans = inf;
    for(int i = m; i <= 2 * m; i++){
        ans = min(ans, f[i]);
    }
    ans == inf ? puts("no solution") : printf("%d\n", ans);
    return 0;
}