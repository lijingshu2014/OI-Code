#include <bits/stdc++.h>
using namespace std;
bool isp(int n) {
	if(n < 2) return 0;
	for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return 0;
    }
	return 1;
}
int main() {
    int m, n;
	cin >> m >> n;
    bool f1 = 0, f2 = 0;
	for (int i = m; i <= n; i++) {
		string t = to_string(i);
		reverse(t.begin(), t.end());
		int j = stoi(t);
		if (isp(i) && isp(j)) {
			if (f1) cout << ",";
			cout << i;
			f1 = 1;
			f2 = 1;
		}
	}
	if (!f2) cout << "No";
	return 0;
}