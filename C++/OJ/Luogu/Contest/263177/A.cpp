#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z, a;
    cin >> x >> y >> z >> a;
    int p1 = a * x, p2 = 0;
    if (a >= y) p2 = a * z;
    else p2 = y * z;
    cout << min(p1, p2);
    return 0;
}