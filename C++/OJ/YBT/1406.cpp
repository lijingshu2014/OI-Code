#include<bits/stdc++.h>
using namespace std;
string s[205];
int main() {
	cin >> s[1];
	int tmp = 1;
	while(getchar() == ' '){
		tmp++;
		cin >> s[tmp];
	}
	string a, b;
	cin >> a >> b;
	for(int i = 1; i <= tmp; i++) {
		if(s[i] == a) cout << b;
		else cout << s[i];
		cout << ' ';
	}
	return 0;
}