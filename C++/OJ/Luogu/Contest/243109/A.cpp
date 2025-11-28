#include <iostream>
using namespace std;
int T, n, m;
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n == 1 || m == 1) cout << 1 << endl;
        else cout << n + m - 1 << endl;
    }
    return 0;
}