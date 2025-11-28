#include <bits/stdc++.h>
using namespace std;
bool isrun(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int d_in_m(int y, int m) {
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isrun(y)) return 29;
    return d[m - 1];
}
int main() {
    int cury = 2025, curm = 3, curd = 29, next = cury + 1;
    while (1) {
        int root = 1;
        while (root * root < next) root++;
        if(root * root == next) break;
        next++;
    }
    int tot = 0;
    for (int m = curm; m <= 12; m++) {
        if (m == curm) tot += d_in_m(cury, m) - curd;
        else tot += d_in_m(cury, m);
    }
    for (int y = cury + 1; y < next; y++){
    	if(isrun(y)) tot += 366;
    	else tot += 365;
	}
    cout << tot + 1;
    return 0;
}    