#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N], ans;

int main() {
    cin >> n;
    // f[i] ǰ1~i����ĸ������i��β�ĵ��������г���
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
