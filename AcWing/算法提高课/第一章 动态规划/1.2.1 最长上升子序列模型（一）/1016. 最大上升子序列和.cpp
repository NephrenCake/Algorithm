#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, a[N], f[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + a[i]);
        ans = max(ans, f[i]);
    }

    cout << ans;
    return 0;
}
