#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1103/

#define x first
#define y second
#define PII pair<int, int>
const int N = 210;

char g[N][N];
int dist[N][N];
int r, c;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(PII start, PII end) {
    queue<PII> q;
    q.push(start);
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        if (t == end)
            return dist[t.x][t.y];
        int x = t.x, y = t.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && dist[nx][ny] == 0 && g[nx][ny] != '#') {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> r >> c;
        PII start, end;
        memset(dist, 0, sizeof dist);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'S') start = {i, j};
                else if (g[i][j] == 'E') end = {i, j};
            }
        int d = bfs(start, end);
        if (d == -1)
            cout << "oop!" << endl;
        else
            cout << d << endl;
    }
}
