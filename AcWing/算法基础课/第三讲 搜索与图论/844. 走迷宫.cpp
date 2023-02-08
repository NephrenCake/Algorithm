#include <iostream>

using namespace std;

struct P {
    int x, y, d;
};
const int N = 110;
int n, m, a[N][N], used[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
P q[N * N];
int hh = 0, tt = -1;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    q[++tt] = {1, 1, 0};
    while (hh <= tt) {
        P cur = q[hh++];
        if (cur.x == n && cur.y == m) {
            cout << cur.d;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i], y = cur.y + dy[i];
            if (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 0 && !used[x][y]) {
                used[x][y] = true;
                q[++tt] = {x, y, cur.d + 1};
            }
        }
    }
}

// dfs: Time Limit Exceeded
// #include <iostream>
//
// using namespace std;
//
// const int N = 110;
// int n, m, a[N][N], used[N][N], ans = 0x3f3f3f3f;
// int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
//
// void dfs(int x, int y, int cur) {
//     if (cur >= ans)
//         return;
//     if (x == n && y == m) {
//         ans = min(ans, cur);
//         return;
//     }
//
//     for (int i = 0; i < 4; i++) {
//         int nx = x + dx[i], ny = y + dy[i];
//         if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !used[nx][ny] && a[nx][ny] == 0) {
//             used[nx][ny] = true;
//             dfs(nx, ny, cur + 1);
//             used[nx][ny] = false;
//         }
//     }
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> a[i][j];
//
//     dfs(1, 1, 0);
//     cout << ans;
// }
