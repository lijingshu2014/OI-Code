#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int n, k, a[10005];
    cin >> n >> k;
    for(int i = 0;i < n;i++){
		cin >> a[i];
	}
    sort(a, a + n);
    int ans = unique(a, a + n) - a;
    if(k < ans){
		cout << a[k - 1];
	}
    else{
		cout << "NO RESULT";
	}
    return 0;
}