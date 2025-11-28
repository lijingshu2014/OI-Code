#include <bits/stdc++.h>
using namespace std;
char G[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= W; j++) {
            G[i][j] = s[j - 1];
        }
    }
    for (int x = 1; x <= H; x++) {
        for (int y = 1; y <= W; y++) {
            if (G[x][y] == '#') {
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int tx = x + dx[d];
                    int ty = y + dy[d];
                    if (tx >= 1 && tx <= H && ty >= 1 && ty <= W) {
                        if (G[tx][ty] == '#') cnt++;
                    }
                }
                if (cnt != 2 && cnt != 4) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}