#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, y, s, t;
    cin >> n >> y >> s >> t;
    for (int i = 1; i <= n; i++) {
        int start = (i - 1) * s;
        int end = i * s;
        if ((start - y) % t != 0 && (end - y) % t != 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}