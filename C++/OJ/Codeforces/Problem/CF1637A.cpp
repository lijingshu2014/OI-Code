#include<iostream>
using namespace std;
int a[10004];
int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		int n;
		cin >> n;
		for(int j = 1;j <= n;j++) cin >> a[j];
		bool flag = 0;
		for(int j = 1;j <= n - 1;j++){
			for(int k = j + 1;k <= n;k++){
				if(a[k] < a[j]){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}