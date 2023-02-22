#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (b) {
        int d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
    x = 1, y = 0;
    return a;
}

int main() {
    int n, a, b, x, y;
    cin >> n;
    while (n-- && cin >> a >> b) {
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
}
