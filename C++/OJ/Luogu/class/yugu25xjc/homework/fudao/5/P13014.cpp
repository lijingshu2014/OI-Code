#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int gcd (int a, int b){return b ? gcd(b, a % b) : a;}
int main(){
    int n, q;
    cin >> n >> q;
    int g = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i != 1) g = gcd(abs(a[i] - a[i - 1]), g);
    }
    for(int i = 1;i <= q;i++) cout << gcd(a[i] + i, g) << endl;
    return 0;
}