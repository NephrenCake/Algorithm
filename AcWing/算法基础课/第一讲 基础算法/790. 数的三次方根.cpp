#include <iostream>

using namespace std;

double l = -10000, r = 10000, m, tar;

int main() {
    cin >> tar;
    while (l + 1e-8 < r) {
        m = (l + r) / 2;
        if (m * m * m < tar) l = m;
        else r = m;
    }
    printf("%.6f", r);
}
