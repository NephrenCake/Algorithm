#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1115/

#define x first
#define y second
#define PII pair<int, int>
const int N = 30;

char g[N][N];
bool used[N][N];
int w, h;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(PII start) {
    int ans = 1;
    queue<PII > q;
    q.push(start);
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && !used[nx][ny] && g[nx][ny] != '#') {
                ans++;
                used[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return ans;
}

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            return 0;
        PII start;
        memset(used, 0, sizeof used);
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++) {
                cin >> g[i][j];
                if (g[i][j] == '@') {
                    start = {i, j};
                    used[i][j] = true;
                }
            }

        cout << bfs(start) << endl;
    }
}
