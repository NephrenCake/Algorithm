#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N], ans;

int main() {
    cin >> n;
    // f[i] 前1~i个字母并且以i结尾的单增子序列长度
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans;
}
