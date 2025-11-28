#include <iostream>
using namespace std;
const int mod = 20123;
int n, m;
int floor[10005][105][3];
int num[10005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j <= m - 1; j++) {
            cin >> floor[i][j][1] >> floor[i][j][2];
            if (floor[i][j][1]) count++;
        }
        num[i] = count;
    }
    int start;
    cin >> start;
    int ans = 0;
    for (int i = 1, j = start; i <= n; i++) {
        ans = (ans + floor[i][j][2]) % mod;
        int step = floor[i][j][2];
        if(floor[i][j][1]) step--; 
        step %= num[i];
        if (step == 0) step = num[i];
        while (step > 0) {
            j = (j + 1) % m;
            if (floor[i][j][1]) step--;
        }
    }
    cout << (ans + mod) % mod;
    return 0;
}