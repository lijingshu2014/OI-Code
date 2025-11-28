#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[200], b[200], c[200];
int main() {    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> c[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t < k; t++) {
                int tmp = (a[i] * b[j]) % c[t];
                if (tmp > ans) ans = tmp;
            }
        }
    }
    cout << ans;
    return 0;
}