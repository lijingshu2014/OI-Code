#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("number.in", "r", stdin);
    // freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int cnt[10] = {0};
    for(int i = 0;i < s.size();i++){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            cnt[c - '0']++;
        }
    }
    string ans = "";
    for(int i = 9;i >= 0;i--){
        while(cnt[i] > 0){
            ans += char('0' + i);
            cnt[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}