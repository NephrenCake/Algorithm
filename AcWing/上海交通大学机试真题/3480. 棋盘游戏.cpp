#include <iostream>

using namespace std;

int g[6][6], x1, y1, x2, y2, used[7][7], ans = 0x3f3f3f3f;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int cx, int cy, int cost, int st) {
    if (cost > ans) return;
    if (cx == x2 && cy == y2) {
        ans = cost;
        return;
    }

    used[cx][cy] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (0 <= nx && nx <= 5 && 0 <= ny && ny <= 5 && !used[nx][ny])
            dfs(nx, ny, cost + st * g[nx][ny], st * g[nx][ny] % 4 + 1);
    }
    used[cx][cy] = 0;
}

int main() {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            cin >> g[i][j];
    cin >> x1 >> y1 >> x2 >> y2;
    dfs(x1, y1, 0, 1);
    cout << ans;
}
