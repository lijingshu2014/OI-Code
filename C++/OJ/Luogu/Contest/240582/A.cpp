#include<bits/stdc++.h>
using namespace std;
int T, a, b, x, y;
int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b >> x >> y;
        int ans = 1e9;
        for (int i = 0; i * 2 <= a; i++) {
            for (int j = 0; j * 2 <= b; j++) {
                int tmp1 = a - 2 * i, tmp2 = b - 2 * j, t = min(tmp1, tmp2);
                if (tmp1 - t == 0 || tmp2 - t == 0) {
                    int cost = i * x + j * x + t * y;
                    ans = min(ans, cost);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}