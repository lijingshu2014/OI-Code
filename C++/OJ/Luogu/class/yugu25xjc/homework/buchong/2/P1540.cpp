#include<queue>
#include<iostream>
using namespace std;
queue<int> q;
int main(){
    int m, n, x;
    cin >> m >> n;
    int ans = 0;
    bool flag[1005] = {0};
    for(int i = 1;i <= n;i++){
        cin >> x;
        if(flag[x] == 0){
            ans++;
            if(q.size() >= m){
                flag[q.front()] = 0;
                q.pop();
            } 
            q.push(x);
            flag[x] = 1;
        }
    }
    cout << ans;
    return 0;
}