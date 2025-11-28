#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MAXM = 20;
bool vis[MAXN];
int a[MAXN][MAXM];
int n, m;
bool check(int i, int k) {
    
    memset(vis, 1, sizeof(vis));
    vis[i] = 0; 

    for (int step = 0; step < k; step++) {
        bool f = 0;
        int X = -1;
        int cnt_max = -1;
        for (int x = 0; x < m; x++) {
            int cnt_yes = 0;
            int cnt_no = 0;
            for (int j = 0; j < n; j++) {
                if (vis[j]) {
                    if (a[j][x] == a[i][x]) cnt_yes++;
                    else cnt_no++;
                }
            }
            if (cnt_yes > 0 || cnt_no > 0) {
                if (cnt_yes > cnt_max || (cnt_yes == cnt_max && x < X)) {
                    cnt_max = cnt_yes;
                    X = x;
                }
                if (cnt_no > cnt_max || (cnt_no == cnt_max && x < X)) {
                    cnt_max = cnt_no;
                    X = x;
                }
            }
        }

        if (X == -1) return 0;
        bool flag = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j] && a[j][X] == a[i][X]) {
                flag = 1;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                if (flag && a[j][X] != a[i][X]) {
                    vis[j] = 0;
                } else if (!flag && a[j][X] == a[i][X]) {
                    vis[j] = 0;
                }
            }
        }
        int cnt = 0;
        int last = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                cnt++;
                last = j;
            }
        }
        if (cnt == 1 && last == i) {
            return 1;
        }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        if (vis[j]) {
            cnt++;
        }
    }
    return cnt == 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(i, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}