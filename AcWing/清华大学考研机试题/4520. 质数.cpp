#include <iostream>

using namespace std;

bool is_prime(int x) {
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int t, x;
    cin >> t;
    while (t-- && cin >> x) {
        for (int i = 1; ; i++) {
            int len = to_string(i).size(), c = x;
            while (len--) c *= 10;
            c += i;
            if (is_prime(c)) {
                cout << c << endl;
                break;
            }
        }
    }
}
