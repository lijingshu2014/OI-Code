#include<bits/stdc++.h>
using namespace std;
int get(int x){//找x非自身的最大因子
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0){
            return x / i;
        }
    }
    return 1;
}
vector<int> find(int x){
    vector<int> a;
    while(x != 1){
        a.push_back(x);
        x = get(x);
    }
    a.push_back(1);
    return a;
}
int main(){
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        auto a = find(x), b = find(y);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int k = 0;
        while(k + 1 < min(a.size(), b.size()) && a[k + 1] == b[k + 1]){
            k++;
        }
        cout << a.size() - 1 - k + b.size() - 1 - k << endl;
    }
    return 0;
}