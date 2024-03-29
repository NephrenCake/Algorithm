#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + a[i]);
        ans = max(ans, f[i]);
    }
    cout << ans;
}
