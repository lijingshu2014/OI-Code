#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> prime;
bool is_prime[N];
void seive(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2;i < N;i++) is_prime[i] = true;
    for(int i = 2;i < N;i++){
        if(is_prime[i]){
            prime.push_back(i);
            if((long long)i * i >= N) continue;
            for(int j = i * i;j < N;j += i) is_prime[j] = false;
        }
    }
}
int main(){
    seive();
    int t;
    cin >> t;
    while(t--){
        int h;
        cin >> h;
        int ans = INT_MAX;
        for(int i = 0;(1 << i) - 1 <= h;i++){
            int x = (1 << i) - 1;
            if(h - x == 0)
                ans = min(i, ans);
            else if(is_prime[h - x])
                ans = min(i + 1, ans);
        }
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}