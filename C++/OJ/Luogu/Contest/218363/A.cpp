#include<bits/stdc++.h>
using namespace std;
int q;
string a, o, b;
int main(){
    cin >> q;
    while(q--){
        cin >> a >> o >> b;
        if(a == "eat" && b == "eat"){
			cout << "or" << endl;
			continue;
		}
        else if(a == "eat" && b != "eat") {
			b.erase(b.end() - 1);
			cout << b << endl;
		}
        else if(a != "eat" && b == "eat") cout << a << endl;
        else if(a != "eat" && b != "eat") cout << a << endl;
    }
    return 0;
}