#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a == 0) cnt0++;
    }
    cout << cnt0;
    return 0;
}