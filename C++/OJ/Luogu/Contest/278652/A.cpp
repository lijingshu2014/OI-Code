#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        int cnt = 0;
        for (int x = 1; x <= 6; x++) {
            int y = k - x;
            if (y >= x && y <= 6) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}