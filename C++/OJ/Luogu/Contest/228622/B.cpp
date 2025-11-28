#include <iostream>
using namespace std;
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int cw = (y - x + n) % n;
    int ccw = (x - y + n) % n;
    if (cw < ccw) {
        cout << "Clockwise Loop";
    } else if (ccw < cw) {
        cout << "Counter-clockwise Loop";
    } else {
        cout << "\"Wonderful\"";
    }
    return 0;
}