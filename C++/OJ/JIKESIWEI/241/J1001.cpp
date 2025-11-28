#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.size();
    if((s[len - 1] - '0') % 2 == 0) cout << "yes";
    else cout << "no";
    return 0;
}