#include <iostream>

using namespace std;

const int N = 5010;
int a[N][N], ans;

int main() {
    int n, r, x, y, w;
    cin >> n >> r;
    while (n-- && cin >> x >> y >> w) a[x + 1][y + 1] += w;  // 注意题目的下标从0开始，要放在从1开始
    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            ans = max(ans, a[i][j] - a[max(i - r, 0)][j] - a[i][max(j - r, 0)] + a[max(i - r, 0)][max(j - r, 0)]);
        }
    cout << ans;
}
