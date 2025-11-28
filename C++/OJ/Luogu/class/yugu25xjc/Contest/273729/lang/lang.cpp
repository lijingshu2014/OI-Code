#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull TQ = 0x00FFFFFFFFFFFFFFULL;
int main() {
    int T, m;
    cin >> T >> m;
    while (T--) {
        ull x;
        cin >> x;
        if ((x >> 56) == m) {
            ull ans = x & TQ;
            cout << ans << endl;
        } 
        else cout << -1 << endl;
    }
    return 0;
}