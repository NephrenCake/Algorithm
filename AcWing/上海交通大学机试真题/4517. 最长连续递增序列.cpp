#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n, a[N], f[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < a[i]) f[i] = f[i - 1] + 1;
        else f[i] = 1;
        ans = max(ans, f[i]);
    }
    cout << ans;
}
