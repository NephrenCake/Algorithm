#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1098/

const int N = 105;

char g[N][N][N];
int dist[N][N][N];
int l, r, c;
int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 0, 1, 0, -1};
int dy[] = {0, 0, 1, 0, -1, 0};

struct S {
    int z;
    int x;
    int y;
} s, e;

int bfs() {
    queue<S> q;
    q.push(s);
    while (!q.empty()) {
        S t = q.front();
        q.pop();
        if (t.z == e.z && t.x == e.x && t.y == e.y)
            return dist[t.z][t.x][t.y];

        for (int i = 0; i < 6; i++) {
            int nz = t.z + dz[i];
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (1 <= nz && nz <= l && 1 <= nx && nx <= r && 1 <= ny && ny <= c
                && g[nz][nx][ny] != '#' && dist[nz][nx][ny] == -1) {
                // printf("%d %d %d\n", nz, nx, ny);
                q.push({nz, nx, ny});
                dist[nz][nx][ny] = dist[t.z][t.x][t.y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    while (scanf("%d%d%d", &l, &r, &c), l || r || c) {
        for (int k = 1; k <= l; k++)
            for (int i = 1; i <= r; i++)
                for (int j = 1; j <= c; j++) {
                    cin >> g[k][i][j];
                    dist[k][i][j] = -1;
                    if (g[k][i][j] == 'S') {
                        dist[k][i][j] = 0;
                        s = S{k, i, j};
                    }
                    if (g[k][i][j] == 'E')
                        e = S{k, i, j};
                }

        int d = bfs();
        if (d == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", d);
    }
}
