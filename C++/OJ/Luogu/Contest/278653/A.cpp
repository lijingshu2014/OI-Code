#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
int vis[MAXN][MAXM];
struct node{
    int a, b;
}pos[MAXN][MAXM];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        memset(vis, 0, sizeof(vis));
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = i, y = j;
                bool flag = 0;
                for (char c : s) {
                    if (c == 'U') x--;
                    else if (c == 'D') x++;
                    else if (c == 'L') y--;
                    else if (c == 'R') y++;
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    vis[i][j] = 1;
                    pos[i][j] = {x, y};
                } else vis[i][j] = 0;
            }
        }
        int ans = 0;
        for (int h = 0; h < n; h++) {
            for (int w = 0; w < m; w++) {
                int alive = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == h && j == w) continue;
                        bool flag = 0;
                        int x = i, y = j;
                        for (char c : s) {
                            if (c == 'U') x--;
                            else if (c == 'D') x++;
                            else if (c == 'L') y--;
                            else if (c == 'R') y++;
                            if (x == h && y == w) {
                                flag = 1;
                                break;
                            }
                            if (x < 0 || x >= n || y < 0 || y >= m) break;
                        }
                        if (!flag && vis[i][j]) alive++;
                    }
                }
                if (alive == k) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}