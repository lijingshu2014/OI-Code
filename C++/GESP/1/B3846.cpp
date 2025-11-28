#include<bits/stdc++.h>
using namespace std;
bool isrun(int y){
    if(y % 4 == 0){
        if(y % 100 == 0){
            if(y % 400 == 0) return 1;
            else return 0;
        }
        else return 1;
    }
    else return 0;
}
int main(){
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for(int i = a + 1; i < b; i++){
        if(isrun(i)) sum += i;
    }
    cout << sum;
    return 0;
}