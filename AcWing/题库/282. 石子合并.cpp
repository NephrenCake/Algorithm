#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/284/

const int N = 310;
int n;
int s[N];
int f[N][N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i], s[i] += s[i - 1];
    }

    for (int len = 2; len <= n; ++len) {
        // 1. 区间问题一般先枚举长度。区间定义一般左闭右闭，包含 i、j 两个端点
        // j = i + len - 1;
        // 因此，len >= 2，长度 2 至少包含 i、j 两个点，j 不与 i 重合
        for (int i = 1; i + len - 1 <= n; ++i) {
            // 2. 在枚举区间起点
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; ++k) {
                // 注意，f[i][j] 一直在维护一个最小值
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    // 循环和状态表示的形式不一定相同，输出结果要遵循集合的定义
    cout << f[1][n];
}
