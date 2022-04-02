#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1235/

/**
 * 1. 先找到有多少个连通块
 * 2. 多少个会被淹没
 *          统计 total、bound
 *          当 total == bound，则淹没一个岛屿
 */

#define x first
#define y second
typedef pair<int, int> PII;

const int N = 1010;

char g[N][N];
bool used[N][N];
int n;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(PII start) {
    int total = 0, bound = 0;
    queue<PII> q;
    q.push(start);
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        bool is_edge = false;
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && g[nx][ny] == '#' && !used[nx][ny]) {
                q.push({nx, ny});
                used[nx][ny] = true;
            }
            if (g[nx][ny] == '.')
                is_edge = true;
        }
        if (is_edge)
            bound++;
        total++;
    }

    return total == bound;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == '#' && !used[i][j])
                ans += bfs({i, j});
    cout << ans;
}
