#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
int n, m;
int p[N], c[N];
vector<ll> sum[N];//sum[i]表示数字i从小到大的代价前缀和
ll work(int k){
    int cnt = sum[1].size();
    ll cost = 0;
    vector<int> start(n + 1, 0);
    for(int i = 2;i <= n;i++){
        int len = sum[i].size();
        if(len >= k){// len-(k-1) -> len-k+1
            cost += sum[i][len-k];
            cnt += len - k + 1;
            start[i] = len - k + 1;
        }
    }
    if(cnt < k){
        vector<int> rem;
        for(int i = 2;i <= n;i++){
            for(int j = start[i];j < sum[i].size();j++){
                if(j == 0){
                    rem.push_back(sum[i][j]);
                }else{
                    rem.push_back(sum[i][j] - sum[i][j - 1]);
                }
            }
        }
        sort(rem.begin(), rem.end());
        for(int i = 0; i < k - cnt;i++){
            cost += rem[i];
        }
    }
    return cost;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> p[i] >> c[i];
        sum[p[i]].push_back(c[i]);
    }
    for(int i = 1;i <= n;i++){
        sort(sum[i].begin(), sum[i].end());
        for(int j = 1;j < sum[i].size();j++){
            sum[i][j] += sum[i][j - 1];
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int i = 1;i <= m;i++){
        ans = min(ans, work(i));
    }
    cout << ans << endl;
    return 0;
}