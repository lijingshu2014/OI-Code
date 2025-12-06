#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN], vis[MAXN];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) vis[i] = 1;
    int cnt = 0;
    while(q--){
        int x;
        cin >> x;
        if (vis[x] == 1) {
            vis[x] = 0;
            if (a[x] == 1) cnt++;
        }
        else {
            if (a[x] == 1) cnt--;
            vis[x] = 1;
        }
        if (cnt > 0) {
            if (a[x] == 0 && vis[x] == 0) {
                a[x] = 1;
                cnt++; 
            }
        }
        bool flag = 0;
        if (cnt > 0) flag = 1;
        if (flag) {
            if (vis[x] == 0) {
                if (a[x] == 0) {
                    if (cnt > 0) {
                        a[x] = 1;
                        cnt++;
                    }
                }
            }
            bool fl = 0;
            if (cnt > 0) fl = 1;
            if (fl) {
                if (a[x] == 0 && vis[x] == 0) {
                    a[x] = 1;
                    cnt++; 
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}