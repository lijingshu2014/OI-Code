#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    if(s[0] == '-'){
        int sum = 0;
        for(int i = 1;i < len;i++){
            sum += s[i] - '0';
        }
        if(sum % 3 == 0){
            if((s[len - 1] - '0') % 2 == 0){
                cout << "yes";
            }else{
                cout << "no";
                return 0;
            }
        }else{
            cout << "no";
            return 0;
        }
    }else{
        int sum = 0;
        for(int i = 0;i < len;i++){
            sum += s[i] - '0';
        }
        if(sum % 3 == 0){
            if((s[len - 1] - '0') % 2 == 0){
                cout << "yes";
            }else{
                cout << "no";
                return 0;
            }
        }else{
            cout << "no";
            return 0;
        }
    }
    return 0;
}