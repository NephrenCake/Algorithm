#include <iostream>

using namespace std;

const int N = 310;
int r, c, a[N][N], f[N][N], ans;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int dfs(int cx, int cy) {
    if (f[cx][cy] != 0) return f[cx][cy];
    f[cx][cy] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (1 <= nx && nx <= r && 1 <= ny && ny <= c && a[cx][cy] > a[nx][ny])
            f[cx][cy] = max(f[cx][cy], dfs(nx, ny) + 1);
    }
    return f[cx][cy];
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, dfs(i, j));
    cout << ans;
}
