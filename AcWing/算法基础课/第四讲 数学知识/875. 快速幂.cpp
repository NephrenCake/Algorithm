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
    int n, a, b, p;
    cin >> n;
    while (n-- && cin >> a >> b >> p)
        cout << qmi(a, b, p) << endl;
}
