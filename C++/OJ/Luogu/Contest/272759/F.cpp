#include <bits/stdc++.h>
using namespace std;
void split(int num, int digits[]) {
    digits[0] = num / 1000;
    digits[1] = (num / 100) % 10;
    digits[2] = (num / 10) % 10;
    digits[3] = num % 10;
}
int func(int digits[]) {
    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}
void Sort1(int digits[]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] < digits[j]) {
                int tmp = digits[i];
                digits[i] = digits[j];
                digits[j] = tmp;
            }
        }
    }
}
void Sort2(int digits[]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] > digits[j]) {
                int tmp = digits[i];
                digits[i] = digits[j];
                digits[j] = tmp;
            }
        }
    }
}
int Pnum(int num) {
    while (num != 6174) {
        int digits[4];
        split(num, digits);
        Sort1(digits);
        int Max = func(digits);
        Sort2(digits);
        int Min = func(digits);
        num = Max - Min;
    }
    return num;
}
int main() {
    char s[1000];
    cin.getline(s, 1000);
    int len = strlen(s), st = -1, cnt = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            cnt++;
            if (cnt == 1) st = i;
        }
        else cnt = 0;
    }
    int num = 0;
    for (int i = 0; i < 4; i++) num = num * 10 + (s[st + i] - '0');
    char res[5];
    sprintf(res, "%04d", Pnum(num));
    for (int i = 0; i < 4; i++) s[st + i] = res[i];
    cout << s;
    return 0;
}
