#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b > d){
        d += 60;
        c--;
    }
    int ans = (c - a) * 60 + (d - b);
    cout << ans;
    return 0;
}