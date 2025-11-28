#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    long long mi = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            long long os = 0;
            for (int i = l; i <= r; i++) {
                os += a[i];
            }
            long long ns = 1LL * (r - l + 1) * x;
            long long in = ns - os;
            if (in > mi) {
                mi = in;
            }
        }
    }
    cout << sum + mi << endl;
    return 0;
}