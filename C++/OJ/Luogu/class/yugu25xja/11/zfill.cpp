#include<bits/stdc++.h>
using namespace std;

int n, k;
string S;

int main() {
    cin >> n >> k >> S;
    for(int i = 1; i <= n - k; i++) {
        cout << '0';
    }
    cout << S << endl;
    return 0;
}