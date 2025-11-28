#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, cnt = 0;
        cin >> n;
        for(int i = 2;i * i <= n;i++){
            cnt += (n % i == 0);
            while(n % i == 0) n /= i;
        }
        cnt += (n != 1);
        cnt == 2 ? puts("1") : puts("0");
    }
    return 0;
}