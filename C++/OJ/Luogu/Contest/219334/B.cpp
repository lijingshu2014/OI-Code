#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005], b[1000005];
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    if(m == 2){
        for(int i = 1;i <= k;i++){
			cout << i << ' ' << i % n + 1 << endl;
        }
        return 0;
    }
    for(int i = 0;i < k;i++){
        int x = i;
        for(int j = 1;j < m;j++){
            a[j] = x % n + 1;
            x /= n;
        }
        int s = 0;
        for(int j = 1;j < m;j++) s ^= a[j];
        cout << s;
        for(int j = 1;j < m;j++) cout << ' ' << a[j];
        cout << endl;
    }
    return 0;
}