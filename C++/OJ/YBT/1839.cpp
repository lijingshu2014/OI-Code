#include<bits/stdc++.h>
using namespace std;
string name[105];
int n, money[105];
int main(){
    int qimo, banping, lunwen, sum = 0, Max = 1;
    char isganbu, iswest;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> name[i] >> qimo >> banping >> isganbu >> iswest >> lunwen;
        if(qimo > 80 && lunwen >= 1) money[i] += 8000;
        if(qimo > 85 && banping > 80) money[i] += 4000;
        if(qimo > 90) money[i] += 2000;
        if(qimo > 85 && iswest == 'Y') money[i] += 1000;
        if(banping > 80 && isganbu == 'Y') money[i] += 850;
        if(money[i] > money[Max]) Max = i;
        sum += money[i];
    }
    cout << name[Max] << endl << money[Max] << endl << sum;
    return 0; 
}   