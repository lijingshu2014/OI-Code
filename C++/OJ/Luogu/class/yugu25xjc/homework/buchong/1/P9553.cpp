#include<bist/stdc++.h>
using namespace std;
int n, m, k, d[1000005], s[205], t[1005], word1[1005], word2[1005];
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> d[i];
    for(int i = 1;i <= m;i++) cin >> s[i];
    for(int i = 1;i <= k;i++) cin >> t[i];
    for (int i = 1; i <= n; i++) word1[d[i]]++;
    for (int i = 1; i <= m; i++){
        word1[s[i] + 1] += word1[s[i]];
        word1[s[i]] = 0;
    }
    int ans = -2147483647;
    for(int i = 1;i <= n;i++) ans = max(d[i], ans);
    for (int i = 1; i <= ans; i++) {
        if (word1[i] == 0) continue;
        for (int j = 1; j <= k; j++) {
            word2[i + t[j]] += word1[i]; 
            ans = max(ans, i + t[j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        word2[s[i] + 1] += word2[s[i]]; 
        word2[s[i]] = 0;
    }
    while (word1[ans] == 0 && word2[ans] == 0) ans--;
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        cout << word1[i] << " " << word2[i] << endl;
    }
    return 0;
}