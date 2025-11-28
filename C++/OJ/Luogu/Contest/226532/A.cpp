#include <iostream>
using namespace std;
int main() {
    int n, T;
    cin >> n >> T;
    int a[10], b[10];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) sum1 += a[i];
    if (sum1 < T) {
        cout << sum1 << endl;
    } else {
        for (int i = 0; i < n; i++) sum2 += b[i];
        cout << sum2 << endl;
    }
    return 0;
}