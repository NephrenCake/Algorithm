#include <iostream>

using namespace std;

const int N = 110;
int n, k, a[N], f[N], ans;

int main() {
    cin >> k;
    while (k-- && cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        for (int i = n; i >= 1; i--) {
            f[i] = 1;
            for (int j = n; i < j; j--)
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
}
