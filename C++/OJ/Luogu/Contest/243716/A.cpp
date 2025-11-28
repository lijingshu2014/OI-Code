#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll m;
        scanf("%lld", &m);
        ll L;
        if (m == 1) {
            printf("Lose!\n");
            continue;
        }
        ll s = (ll)(sqrt(8 * m + 1) + 1) / 2;
        while (s * (s - 1) / 2 < m) {
            s++;
        }
        L = s;
        ll R = 2 * m - 2;
        if (L > R) {
            printf("Lose!\n");
        } else {
            printf("%lld %lld\n", L, R);
        }
    }
    return 0;
}