#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 16;
int n, m = 8, a[N][N];
double f[N][N][N][N][N], X;

double get(int x1, int y1, int x2, int y2) {  //求该矩阵的 n\sigma^2
    double delta = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
    delta = delta - X;
    return delta * delta;
}

double dp(int k, int x1, int y1, int x2, int y2) {
    if (f[k][x1][y1][x2][y2] >= 0) return f[k][x1][y1][x2][y2]; //记忆化搜索
    if (k == n) return f[k][x1][y1][x2][y2] = get(x1, y1, x2, y2);  //更新初始状态

    double t = 1e9; //初始化为无穷大
    for (int i = x1; i < x2; i++) { //横着切
        t = min(t, dp(k + 1, x1, y1, i, y2) + get(i + 1, y1, x2, y2));
        t = min(t, dp(k + 1, i + 1, y1, x2, y2) + get(x1, y1, i, y2));
    }
    for (int i = y1; i < y2; i++) { //竖着切
        t = min(t, dp(k + 1, x1, y1, x2, i) + get(x1, i + 1, x2, y2));
        t = min(t, dp(k + 1, x1, i + 1, x2, y2) + get(x1, y1, x2, i));
    }
    return f[k][x1][y1][x2][y2] = t;
}

int main() {
    cin >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    memset(f, -1, sizeof f);
    X = (double) a[m][m] / n;
    printf("%.3lf\n", sqrt(dp(1, 1, 1, m, m) / n));
}
