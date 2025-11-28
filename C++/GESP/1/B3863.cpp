#include<bits/stdc++.h>
using namespace std;
int main(){
    int X, Y, Z, Q;
    cin >> X >> Y >> Z >> Q;
    int sum = 2 * X + 5 * Y + 3 * Z;
    if(sum <= Q){
        cout << "Yes" << endl;
        cout << Q - sum;
    }else if(sum > Q){
        cout << "No" << endl;
        cout << sum - Q;
    }
    return 0;
}