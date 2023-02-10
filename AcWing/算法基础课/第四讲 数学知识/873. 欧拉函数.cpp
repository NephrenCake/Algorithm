#include <iostream>

using namespace std;

int phi(int a) {
    int res = a;
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            res = res / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res = res / a * (a - 1);
    return res;
}

int main() {
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        cout << phi(a) << endl;
    }
}
