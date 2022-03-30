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
        // �ȵ���ԭ����棬������ԭ�ڴ�ռ���������ǰ׺������
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;  // ע����� xy���ݷ�Χ0~5k����Ҫ��xy++
        sum[x][y] += w;  // ע����� ��Ŀ˵�����Ŀ����ܻ������ͬһ������
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    for (int i = 1; i <= max_x; i++)
        for (int j = 1; j <= max_y; j++)
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];  // ԭ�ع���ǰ׺��

    // ������r��С��Ҳ������ǰ׺�������ø�rһ����
    int max_x_r = min(r, max_x), max_y_r = min(r, max_y);

    int ans = 0;
    for (int i = max_x_r; i <= max_x; i++)
        for (int j = max_y_r; j <= max_y; j++)
            ans = max(ans, sum[i][j] + sum[i - max_x_r][j - max_y_r] - sum[i][j - max_y_r] - sum[i - max_x_r][j]);
    cout << ans;
}
