#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll l, r;
	cin >> l >> r;
	cout << (l + r) * (r - l + 1) / 2 % 9;
	return 0;
}