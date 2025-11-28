#include<bits/stdc++.h>
using namespace std;
const int N = 1001 * 1001;
bool vis[N + 5];
int ans[N];
int main(){
    int a, n;
    cin >> a >> n;
    for(int i = ceil(sqrt(a));i * i <= N;i++){// i 是平方根
        for(int j = 1;1ll * j * i * i <= N;j++){
            vis[j * i * i] = true;
        }
    }
    int now;
    for(int i = N;i >= 1;i--){
        if(vis[i]) now = i;
        ans[i] = now;
    }
    while(n--){
        int x;
        cin >> x;
        if(vis[x]) cout << "lucky" << endl;
        else cout << ans[x] << endl;
    }
    return 0;
}