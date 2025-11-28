#include <bits/stdc++.h>
using namespace std;
int s[100005], vis[100005];
int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
        int n;
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        bool flag = 1;
		for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
			if (!vis[s[i]]) vis[s[i]] = 1;
			else if (s[i - 1] != s[i]) flag = 0;
		}
        printf("Case #%d: ", c);
		if (!flag) printf("IMPOSSIBLE\n");
		else {
			for (int i = 1;i <= n; i++){
				if (s[i] != s[i - 1]) printf("%d ", s[i]);
            }
			cout << endl;
		}
	}
	return 0;
}