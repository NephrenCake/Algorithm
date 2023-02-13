#include <iostream>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int count(int d, int m, int y) {
    days[2] = y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 29 : 28;
    while (--m) d += days[m];
    while (--y) d += y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 366 : 365;
    return d;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        a = count(a % 100, a / 100 % 100, a / 10000);
        b = count(b % 100, b / 100 % 100, b / 10000);
        cout << abs(a - b) + 1 << endl;
    }
}
