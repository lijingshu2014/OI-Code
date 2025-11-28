#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    char d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if(d == 'A'){
        ans += a * 60 * 60 + b * 60 + c;
    }else if(d == 'P'){
        ans += (a + 12) * 60 * 60 + b * 60 + c;
    }
    cout << ans;
    return 0;
}