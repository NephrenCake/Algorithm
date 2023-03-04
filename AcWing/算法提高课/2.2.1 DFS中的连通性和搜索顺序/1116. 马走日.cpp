#include <iostream>

using namespace std;

const int N = 30;
int t, n, m, x, y, used[N][N], ans;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, 2, 1, -1, -2};

void dfs(int cx, int cy, int cnt) {
    if (cnt == n * m) {
        ans++;
        return;
    }
    used[cx][cy] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny])
            dfs(nx, ny, cnt + 1);
    }
    used[cx][cy] = 0;
}

int main() {
    cin >> t;
    while (t-- && cin >> n >> m >> x >> y) {
        ans = 0;
        dfs(x, y, 1);
        cout << ans << endl;
    }
}
