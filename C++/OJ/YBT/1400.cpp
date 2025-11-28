#include<bits/stdc++.h>
using namespace std;
string init (string s) {
	for (int i = 0; i < s.length(); i++){
        if ('A' <= s[i] && s[i] <= 'Z') s[i] += 32;
    }
	return ' ' + s + ' ';
}
int main() {
    string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
    s1 = init(s1);
	s2 = init(s2);
    int ans = 1e9, cnt = 0;
	for (int i = 0; i < s2.length(); i++){
        if (s2.substr(i, s1.length()) == s1){
            ans = min(ans, i);
            cnt++;
        }
    }
	if (cnt) cout << cnt << ' ' << ans;
	else cout << -1;
	return 0;
}