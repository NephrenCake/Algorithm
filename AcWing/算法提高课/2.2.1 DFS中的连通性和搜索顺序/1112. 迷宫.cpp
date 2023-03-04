#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int k, n, a[N][N], used[N][N], x1, y1, x2, y2, flag;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string s;

void dfs(int x, int y) {
    if (x == x2 && y == y2) flag = 1;
    if (flag) return;

    used[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1 && !used[nx][ny] && a[nx][ny] == 0)
            dfs(nx, ny);
    }
}

int main() {
    cin >> k;
    while (k-- && cin >> n) {
        memset(a, 0, sizeof a);
        memset(used, 0, sizeof used);
        flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++)
                if (s[j] == '#') a[i][j] = 1;
        }
        cin >> x1 >> y1 >> x2 >> y2;
        if (a[x1][y1] == 0 && a[x2][y2] == 0)
            dfs(x1, y1);
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
