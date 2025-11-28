#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 5;
const int M = 1e5 + 5;
string s;
int a[N];
int f[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m;
    cin >> s;
    for(int i = 1;i <= m;i++){
        // abc
        f[i] = f[i - 1];
        for(int j = 1;j <= n;j++){
            if(i < 3 * j) break;
            // s[i - 3 * j ... i - 1] 个 abc
            bool is_match = true;
            if(s[i - 1 - j * 3 + 1] != 'a') break;
            if(s[i - 1 - j * 3 + 2] != 'b') break;
            if(s[i - 1 - j * 3 + 3] != 'c') break;
            f[i] = max(f[i], f[i - 3 * j] + a[j]);
        }
    }
    cout << f[m];
    return 0;
}