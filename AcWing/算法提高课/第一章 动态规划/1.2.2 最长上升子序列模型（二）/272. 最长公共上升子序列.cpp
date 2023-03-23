#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;
int n, f[N][N], ans;  // ��a����ǰi������b����ǰj������������b[j]��β����������������еĳ���
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++) {
    //         f[i][j] = f[i - 1][j];
    //         if (a[i] == b[j]) {
    //             f[i][j] = max(1, f[i][j]);
    //             for (int k = 1; k < j; k++)
    //                 if (b[k] < b[j])
    //                     f[i][j] = max(f[i][j], f[i - 1][k] + 1);
    //         }
    //         ans = max(ans, f[i][j]);
    //     }
    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j])
                maxv = max(maxv, f[i - 1][j] + 1);
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
}
