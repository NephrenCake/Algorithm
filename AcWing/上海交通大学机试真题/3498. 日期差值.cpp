#include <iostream>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a, b;

int cnt(int date) {
    // 从00010101算起为第一天
    int d = date % 100;
    int m = date / 100 % 100;
    int y = date / 10000;
    days[2] = y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 29 : 28;
    while (--m) d += days[m];
    while (--y) d += y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 366 : 365;
    return d;
}

int main() {
    while (cin >> a >> b)
        cout << abs(cnt(a) - cnt(b)) + 1 << endl;
}
