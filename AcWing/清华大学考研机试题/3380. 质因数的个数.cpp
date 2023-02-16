#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        int ans = 0;
        for (int i = 2; i <= n / i; i++)
            if (is_prime(i))
                while (n % i == 0) n /= i, ans++;
        if (is_prime(n)) ans++;
        cout << ans << endl;
    }
}
