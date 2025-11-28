#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main() {
    int n, k;
    cin >> n >> k >> s;
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }
    int base = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) base++;
    }
    int l = 0, h = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) h++;
        else l++;
    }
    int l1 = max(0, k - l);
    int h1 = min(k, h);
    int res = (h1 >= l1) ? (h1 - l1 + 1) : 0;
    cout << res << endl;
    return 0;
}