#include <iostream>

using namespace std;

double n;

int main() {
    cin >> n;
    double l = -10000, r = 10000, m;
    while (l + 1e-8 < r) {
        m = (l + r) / 2;
        if (m * m * m < n) l = m;
        else r = m;
    }
    printf("%.6f", r);
}
