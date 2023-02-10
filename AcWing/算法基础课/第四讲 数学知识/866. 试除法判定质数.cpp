#include <iostream>

using namespace std;

int n;

int is_prime(int a) {
    if (a < 2) return false;
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (is_prime(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
