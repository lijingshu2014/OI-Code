#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int func(int x) {
    int t = 0;
    while (true) {
        bool flag = 0;
        for (int y = 2; y < x; y++) {
            if (gcd(x, y) != 1) {
                x = gcd(x, y);
                t++;
                flag = 1;
                break;
            }
        }
        if (!flag) break;
    }
    return t;
}

int findx(int q) {
    int l = 1, r = 1e6;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (func(mid) < q) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int op, xq;
        cin >> op >> xq;
        if (op == 1) {
            cout << func(xq) << endl;
        } else {
            cout << findx(xq) << endl;
        }
    }
    return 0;
}