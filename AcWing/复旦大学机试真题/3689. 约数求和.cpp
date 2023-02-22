#include <iostream>

using namespace std;

int n;
long long ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += i * (n / i);
    cout << ans;
}
