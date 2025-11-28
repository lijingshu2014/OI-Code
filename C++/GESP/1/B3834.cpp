#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int c = 0;
    for(int i = 1;i <= a;i++){
        for(int j = 1;j <= a;j++){
            if(i <= j && i * j == a){
                c++;
            }
        }
    }
    cout << c;
    return 0;
}