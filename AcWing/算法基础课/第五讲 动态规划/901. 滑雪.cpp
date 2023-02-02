#include <iostream>

using namespace std;

const int N = 310;
int r, c, w[N][N], ans, f[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int dfs(int i, int j) {
    if (f[i][j] != 0) return f[i][j];

    f[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (1 <= nx && nx <= r && 1 <= ny && ny <= c && w[i][j] > w[nx][ny])
            f[i][j] = max(f[i][j], dfs(nx, ny) + 1);
    }
    return f[i][j];  // 注意记得更新f
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> w[i][j];

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, dfs(i, j));
    cout << ans;
}
