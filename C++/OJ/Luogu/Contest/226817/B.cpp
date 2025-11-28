#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005];
int main() {
    cin >> t >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (t % 2 == 1) {
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        return 0;
    }
    int l = 1, r = n;
    while (l <= r) {
        while (l < r && a[l] == l + 1) l++;
        while (l < r && a[r] == r + 1) r--;
        if (l < r) swap(a[l], a[r]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}