#include <bits/stdc++.h>
using namespace std;
int a[15], odd[15], even[15];
int main() {
	int oddcnt = 0, evencnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) even[evencnt++] = a[i];
		else odd[oddcnt++] = a[i];
	}
	sort(odd, odd + oddcnt, greater<int>());
	sort(even, even + evencnt);
	for (int i = 0; i < oddcnt; i++) cout << odd[i] << ' ';
	for (int i = 0; i < evencnt; i++) cout << even[i] << ' ';
	return 0;
}