#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    int start = (s[0] == '-') ? 1 : 0;
    int num_len = len - start;
    int last_three = 0;
    if(num_len >= 3){
        last_three = (s[len - 3] - '0') * 100 + (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
    }else if(num_len == 2){
        last_three = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
    }else if(num_len == 1){
        last_three = s[len - 1] - '0';
    }
    if(last_three % 125 == 0){
        cout << "yes";
    }else{
        cout << "no";
    }
    return 0;
}