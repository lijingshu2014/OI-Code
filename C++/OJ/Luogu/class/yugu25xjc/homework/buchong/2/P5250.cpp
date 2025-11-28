#include<bits/stdc++.h>
using namespace std;
int n;
set<int> s;
int main(){
    cin >> n;
    while(n--){
        int op, len;
        cin >> op >> len;
        if(op == 1){
            if(s.find(len) != s.end()) cout << "Already Exist\n";
            else s.insert(len);
        }else if(s.empty()) cout << "Empty\n";
        else{
            set<int> ::iterator i = s.lower_bound(len), j = i;
            if(j != s.begin()) --j;
            if(i != s.end() && len - *j > *i - len) j = i;
            cout << *j << '\n';
            s.erase(j);
        }
    }
    return 0;
}