#include <iostream>

using namespace std;

typedef long long LL;

LL get_phi(int x) {
    LL res = x;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    int n, a;
    cin >> n;
    while (n-- && cin >> a)
        cout << get_phi(a) << endl;
}
