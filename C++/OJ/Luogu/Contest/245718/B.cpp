#include<bits/stdc++.h>
using namespace std;
int main() {
    int w, f, a, r;
    cin >> w >> f >> a >> r;
    if (w < r) {
        cout << "Rejected";
        return 0;
    }
    if (w != 0) {
        if (f * 100 > w * 20) {
            cout << "Rejected";
            return 0;
        }
        if (a * 100 > w * 30) {
            cout << "Rejected";
            return 0;
        }
    }
    cout << "Accepted";
    return 0;
}