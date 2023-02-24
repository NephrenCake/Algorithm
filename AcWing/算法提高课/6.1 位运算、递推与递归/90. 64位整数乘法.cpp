#include <iostream>

using namespace std;

typedef long long LL;

LL qad(LL a, LL b, LL p) {
    LL res = 0, t = a;
    while (b) {
        if (b & 1) res = (res + t) % p;
        t = (t + t) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    cout << qad(a, b, p);
}
