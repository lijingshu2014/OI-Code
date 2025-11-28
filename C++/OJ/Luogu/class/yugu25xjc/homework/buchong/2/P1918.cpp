#include<iostream>
#include<algorithm>
using namespace std;
struct ball{
    int num;
    int pos;
}a[100005];
bool cmp(ball x, ball y){
    return x.pos < y.pos; 
}
int main(){
    int n, m, q;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].pos;
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> q;
        int l = 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid].pos <= q){
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid - 1;
            }
        }
        if(a[ans].pos == q){
            cout << a[ans].num << endl;
		}
        else{
            cout << 0 << endl;
		}
    }
    return 0; 
}