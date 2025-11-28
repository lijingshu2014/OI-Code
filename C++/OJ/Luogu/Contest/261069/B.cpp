#include <bits/stdc++.h>
using namespace std;
int solve(string s) {
    int n = s.length();
    if (n <= 1) {
        return 0;
    }
    for (int L = n - 1; L >= 1; L--) {
        int diff = 0;
        for (int i = 0; i < L; i++) {
            if (s[i] != s[n - L + i]) {
                diff++;
                if (diff > 1) {
                    break;
                }
            }
        }
        if (diff <= 1) {
            return L;
        }
    }
    return 1;
}
int main() {
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}