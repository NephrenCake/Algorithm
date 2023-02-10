#include <iostream>

using namespace std;

int n, ans;

int main() {
    cin >> n;
    while (n) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans;
}
