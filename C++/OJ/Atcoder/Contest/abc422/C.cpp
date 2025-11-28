#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int T;
    cin >> T;
    while (T--) {
        ll nA, nB, nC;
        cin >> nA >> nB >> nC;
        ll total = nA + nB + nC;
        ll ans = min({nA, nC, total / 3});
        cout << ans << endl;
    }
    return 0;
}