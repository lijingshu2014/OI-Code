#include <bits/stdc++.h>
#define MOD (1LL << 32)
using namespace std;
vector<unsigned int> a(1000001, 1);
vector<unsigned int> b(1000001, 1);
unsigned int func(int n) {
    vector<int> p(n + 1, 0);
    vector<int> need(n + 1, 0);
    unsigned int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            need[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] < need[i]) {
            for (int k = p[i]; k < need[i]; k++) {
                res += a[i] * b[k + 1];
            }
            p[i] = need[i];
        }
        for (int j = 2 * i; j <= n; j += i) {
            p[j]++;
        }
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            cout << func(x) << endl;
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        } else if (op == 3) {
            int x, y;
            cin >> x >> y;
            b[x] = y;
        }
    }
    return 0;
}