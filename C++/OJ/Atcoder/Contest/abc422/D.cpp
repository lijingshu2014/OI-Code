#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    ll K;
    cin >> N >> K;
    int size = 1 << N;
    ll q = K / size;
    int r = K % size;
    int U = (r == 0) ? 0 : 1;
    vector<ll> B(size);
    if (r == 0) {
        for (int i = 0; i < size; i++) B[i] = q;
    } else {
        int step = size / r;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (i % step == 0 && cnt < r) {
                B[i] = q + 1;
                cnt++;
            } 
            else B[i] = q;
        }
    }
    cout << U << endl;
    for (int i = 0; i < size; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}