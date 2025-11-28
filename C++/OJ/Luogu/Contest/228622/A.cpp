#include <iostream>
using namespace std;
int main() {
    int Vegg, Vmilk, Vtart, e, m, t;
    cin >> Vegg >> Vmilk >> Vtart >> e >> m >> t;
    int tot = Vegg * e + Vmilk * m;
    int cnt = (tot % Vtart == 0) ? tot / Vtart : tot / Vtart + 1;
    int ans = (cnt % t == 0) ? cnt / t : cnt / t + 1;
    cout << ans << endl;
    return 0;
}