#include <bits/stdc++.h>
using namespace std;
vector<int> find_se(int m) {
    vector<int> se;
    int power = 1;
    while (power <= m) {
        power <<= 1;
    }
    power >>= 1;
    while (m > 0) {
        if (power <= m) {
            se.push_back(power);
            m -= power;
        }
        power >>= 1;
        while (power > 1 && power <= m) {
            se.push_back(power);
            m -= power;
            power >>= 1;
        }
    }

    while (se.size() & (se.size() - 1)) {
        se.push_back(1);
    }

    return se;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;
        vector<int> se = find_se(m);
        for (int num : se) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}