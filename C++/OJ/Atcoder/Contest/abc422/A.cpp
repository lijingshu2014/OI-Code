#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[4];
    scanf("%s", s);
    int i = s[0] - '0';
    int j = s[2] - '0';
    if (j < 8) printf("%d-%d\n", i, j + 1);
    else printf("%d-%d\n", i + 1, 1);
    return 0;
}