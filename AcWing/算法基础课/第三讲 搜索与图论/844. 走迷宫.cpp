#include <iostream>

using namespace std;

const int N = 110;
int n, m, a[N][N], used[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct P {
    int x, y, d;
} q[N * N];
int hh = 0, tt = -1;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    q[++tt] = {1, 1, 0};
    used[1][1] = 1;
    while (hh <= tt) {
        P cur = q[hh++];
        if (cur.x == n && cur.y == m) {
            cout << cur.d;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i], y = cur.y + dy[i];
            if (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] == 0 && !used[x][y])
                q[++tt] = {x, y, cur.d + 1}, used[x][y] = 1;
        }
    }
}
