#include<bits/stdc++.h>
using namespace std;
int shuwei(int x){
	int res = 0;
	while(x != 0){
		res++;
		x /= 10;
	}
	return res;
}
int zhuanshi(int x, int l, int B){
	int num = 0;
	for(int i = 1;i <= l;i++){
		int tmp = x % 10;
		num += tmp * pow(B, i - 1);
		x /= 10;
	}
	return num;
}
int main(){
	int p, q, r;
	cin >> p >> q >> r;
	int lp, lq, lr;
	lp = shuwei(p);
	lq = shuwei(q);
	lr = shuwei(r);
	for(int B = 2;B <= 40;B++){
		int p10, q10, r10;
		p10 = zhuanshi(p, lp, B);
		q10 = zhuanshi(q, lq, B);
		r10 = zhuanshi(r, lr, B);
		if(p10 * q10 == r10){
			cout << B;
			return 0;
		}
	}
	cout << 0;
	return 0;
}