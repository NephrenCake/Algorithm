#include <iostream>

using namespace std;

long long qmi(int a, int b, int p) {
    long long t = a, res = 1;
    while (b) {
        if (b & 1) res = res * t % p;
        t = t * t % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, a, p;
    cin >> n;
    while (n-- && cin >> a >> p) {
        if (a % p == 0) cout << "impossible" << endl;
        else cout << qmi(a, p - 2, p) << endl;
    }
}
