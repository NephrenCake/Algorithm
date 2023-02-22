#include <iostream>

using namespace std;

long long a, b, c;

int main() {
    while (cin >> a >> b >> c) {
        bool flag = false;
        flag |= ((a + b) == c);
        flag |= ((a - b) == c);
        flag |= ((b - a) == c);
        flag |= ((a * b) == c);
        if (b != 0) flag |= ((a / b) == c && a % b == 0);
        if (a != 0) flag |= ((b / a) == c && b % a == 0);
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
