#include<bits/stdc++.h>
using namespace std;
int n;
char c[200];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++){
		if(c[i] == 'c' || c[i] == 'o' || c[i] == 'd' || c[i] == 'e' || c[i] == 'f' || c[i] == 'r' || c[i] == 's') cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}