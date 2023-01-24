#include <iostream>

using namespace std;

#define x first
#define y second
typedef pair<int, int> point;

int ans = 0x3f3f3f3f, a[6][6], dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
bool used[6][6];
point s, e;

void dfs(int sum, int st, point cur) {
    if (sum > ans)
        return;
    if (cur.x == e.x && cur.y == e.y) {
        ans = min(ans, sum);
        return;
    }

    used[cur.x][cur.y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i], ny = cur.y + dy[i];
        if (0 <= nx && nx <= 5 && 0 <= ny && ny <= 5 && !used[nx][ny]) {
            int cost = a[nx][ny] * st;
            dfs(sum + cost, cost % 4 + 1, {nx, ny});
        }
    }
    used[cur.x][cur.y] = false;
}

int main() {
    for (int i = 0; i <= 5; i++)
        for (int j = 0; j <= 5; j++)
            cin >> a[i][j];
    cin >> s.x >> s.y >> e.x >> e.y;

    dfs(0, 1, s);
    cout << ans;
}
