#include<bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
    cin >> n >> k >> s;
    int l = 0;
    int r = n * n / 4;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int sub = 1, cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
            int cur = cnt0 * cnt1;
            if (cur > mid) {
                sub++;
                cnt0 = (s[i] == '0');
                cnt1 = (s[i] == '1');
            }
        }
        if (sub <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}