#include <bits/stdc++.h>
using namespace std;
int p[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (p[i] != p[i - 1] + 1) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}