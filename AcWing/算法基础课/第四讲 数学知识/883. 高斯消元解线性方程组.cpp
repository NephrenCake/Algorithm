#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];

int gauss() {
    int x, y;  // x代表列 y代表行
    for (x = 0, y = 0; x < n; x++) {
        int t = y;  // 先找到当前这一列，绝对值最大的一个数字所在的行号
        for (int i = y; i < n; i++)
            if (fabs(a[i][x]) > fabs(a[t][x]))
                t = i;
        if (fabs(a[t][x]) < eps) continue;  // 如果当前这一列的最大数都是0，则所有数都是0，不计算
        for (int i = x; i < n + 1; i++) swap(a[t][i], a[y][i]);  // 把当前这一行，换到第r行去
        for (int i = n; i >= x; i--) a[y][i] /= a[y][x];  // 把当前行的同除第一个数，必须从后往前算
        for (int i = y + 1; i < n; i++)  // 把当前列下面的所有数，全部消成0
            if (fabs(a[i][x]) > eps)
                for (int j = n; j >= x; j--)  // 从后往前，当前行的每个数字，都减去对应列 * 行首非0的数字，这样就能保证第一个数字是 a[i][0] -= 1*a[i][0];
                    a[i][j] -= a[y][j] * a[i][x];
        y++;  // 这一行的工作做完，换下一行
    }
    if (y < n) {  // 说明剩下方程的个数是小于 n 的，说明不是唯一解，判断是无解还是无穷多解
        for (int i = y; i < n; i++)  // 因为已经是阶梯型，所以 y ~ n-1 的值应该都为 0
            if (fabs(a[i][n]) > eps)  // a[i][n] 代表 b_i ,即 左边=0，右边=b_i,0 != b_i, 所以无解。
                return 2;
        return 1;  // 否则， 0 = 0，就是r ~ n-1的方程都是多余方程
    }
    for (int i = n - 1; i >= 0; i--)  // 唯一解 ↓，从下往上回代，得到方程的解
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[j][n] * a[i][j];  // 因为只要得到解，所以只用对 b_i 进行操作，中间的值，可以不用操作，因为不用输出
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0)
        for (int i = 0; i < n; i++)
            if (fabs(a[i][n]) > eps) printf("%.2lf\n", a[i][n]);
            else printf("0.00\n");
    else if (t == 1) cout << "Infinite group solutions";
    else cout << "No solution";
}
