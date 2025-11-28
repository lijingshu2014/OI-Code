#include<bits/stdc++.h>
using namespace std;
int months[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
    int y, m;
    cin >> y >> m;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) months[2] = 29;
    cout << months[m];
    return 0;
}