#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int x[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        bool flag = 1;
        for (int i = 1; i < n && flag; i++) {
            if (x[i] < 0) {
                flag = 0;
                break;
            }
            if (i > 0) {
                int diff = x[i] - x[i - 1];
                if (diff > 0) {
                    if (i < 2 || x[i - 2] < diff) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}