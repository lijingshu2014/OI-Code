#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
int n;
int a[N], f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int max_len = 0;
    // f[i]
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        max_len = max(max_len, f[i]);
    }
    cout << max_len;
    return 0;
}