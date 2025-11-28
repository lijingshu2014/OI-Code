#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
bool Int(string n) {
    bool isfu = (n[0] == '-');
    string num = n;
    if (isfu) {
        if (num.length() > 1 + to_string(INT_MIN).length()) return 0;
        if (num.length() == 1 + to_string(INT_MIN).length()) return num <= to_string(INT_MIN);
    } else {
        if (num.length() > to_string(INT_MAX).length()) return 0;
        if (num.length() == to_string(INT_MAX).length()) return num <= to_string(INT_MAX);
    }
    return 1;
}
bool ui(string n) {
    if (n[0] == '-') return 0;
    if (n.length() > to_string(UINT_MAX).length()) return 0;
    if (n.length() == to_string(UINT_MAX).length()) return n <= to_string(UINT_MAX);
    return 1;
}
bool ll(string n) {
    bool isfu = (n[0] == '-');
    string num = n;
    if (isfu) {
        if (num.length() > 1 + to_string(LLONG_MIN).length()) return 0;
        if (num.length() == 1 + to_string(LLONG_MIN).length()) return num <= to_string(LLONG_MIN);
    } else {
        if (num.length() > to_string(LLONG_MAX).length()) return 0;
        if (num.length() == to_string(LLONG_MAX).length()) return num <= to_string(LLONG_MAX);
    }
    return 1;
}
bool ull(string n) {
    if (n[0] == '-') return 0;
    if (n.length() > to_string(ULLONG_MAX).length()) return 0;
    if (n.length() == to_string(ULLONG_MAX).length()) {
        return n <= to_string(ULLONG_MAX);
    }
    return 1;
}
int main() {
    string n;
    cin >> n;
    if (Int(n)) cout << "int" << endl;
    if (ui(n)) cout << "unsigned int" << endl;
    if (ll(n)) cout << "long long" << endl;
    if (ull(n)) cout << "unsigned long long" << endl;
    cout << "string";
    return 0;
}