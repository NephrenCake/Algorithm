#include <iostream>

using namespace std;

int n;

int main() {
    while (cin >> n) {
        int ans = 0;
        for (int i = 2; i <= n / i; i++)
            while (n % i == 0) n /= i, ans++;
        if (n > 1) ans++;
        cout << ans << endl;
    }
}
