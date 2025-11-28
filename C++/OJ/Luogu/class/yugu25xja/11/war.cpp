#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 7;

int n, m;
int T;

long long l, r, mid;

struct Info {
    int r, p, id;
}a[MAXN];

bool comp(Info a, Info b) {
    return (a.r - a.p) != (b.r - b.p) ? ((a.r - a.p) < (b.r - b.p)): (a.id < b.id);
}

bool check(long long x) {
    long long rest = m + x;
    for (int i = 1; i <= n; i++) {
        if(a[i].r - a[i].p <= rest) {
            rest += a[i].p;
        }
        else return false;
    }
    return true;
}

int main() {
    cin >> T;
    while(T--) {
        l = r = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].r >> a[i].p;
            a[i].id = i;
            r += a[i].r - a[i].p;
        }
        sort(a + 1, a + n + 1, comp);
        long long ans = 0;
        while(l <= r) {
            mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid; r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ans == 0) cout << "Yes\n0\n";
        else cout << "No\n" << ans << '\n';
    }
    return 0;
}
