#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/101/

const int N = 5010;

int n, r;
int sum[N][N];
int max_x, max_y;

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        // 先当做原数组存，后面在原内存空间上再做成前缀和数组
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;  // 注意错误 xy数据范围0~5k，需要把xy++
        sum[x][y] += w;  // 注意错误 题目说明多个目标可能会出现在同一格子上
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    for (int i = 1; i <= max_x; i++)
        for (int j = 1; j <= max_y; j++)
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];  // 原地构造前缀和

    // 可以让r变小，也可以让前缀和数组变得跟r一样大
    int max_x_r = min(r, max_x), max_y_r = min(r, max_y);

    int ans = 0;
    for (int i = max_x_r; i <= max_x; i++)
        for (int j = max_y_r; j <= max_y; j++)
            ans = max(ans, sum[i][j] + sum[i - max_x_r][j - max_y_r] - sum[i][j - max_y_r] - sum[i - max_x_r][j]);
    cout << ans;
}
