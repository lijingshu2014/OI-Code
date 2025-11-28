#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int len = s.size();
	for(int i = len - 2;i >= 0;i--){
		cout << s[i];
	}
	return 0;
}