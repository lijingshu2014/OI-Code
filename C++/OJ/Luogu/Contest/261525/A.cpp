#include <bits/stdc++.h>
using namespace std;
int cnt[26] = {0};
int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < n; i++) cnt[t[i] - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}