#include <iostream>
using namespace std;
int n, m, q, a[200005];
struct Pair {
    int x, y;
}lr[200005];
int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> lr[i].x >> lr[i].y;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int res = 0;
        for (int i = l - 1; i < r; i++) {
            int cnt = 0;
            for (int j = lr[i].x - 1; j < lr[i].y; j++) {
                if (a[j] == k) cnt++;
            }
            res = max(res, cnt);
        }
        cout << res << endl;
    }
    return 0;
}