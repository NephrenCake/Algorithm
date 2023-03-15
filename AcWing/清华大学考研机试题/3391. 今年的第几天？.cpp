#include <iostream>

using namespace std;

int y, m, d;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    while (cin >> y >> m >> d) {
        days[2] = y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 29 : 28;
        while (--m) d += days[m];
        cout << d << endl;
    }
}
