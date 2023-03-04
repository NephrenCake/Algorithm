#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;
int w, h, a[N][N], used[N][N], x1, y1, ans;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string s;

void dfs(int x, int y) {
    ans++;
    used[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w && !used[nx][ny] && a[nx][ny] == 0)
            dfs(nx, ny);
    }
}

int main() {
    while (cin >> w >> h, w || h) {
        memset(a, 0, sizeof a);
        memset(used, 0, sizeof used);
        ans = 0;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++)
                if (s[j] == '#') a[i][j] = 1;
                else if (s[j] == '@') x1 = i, y1 = j;
        }
        dfs(x1, y1);
        cout << ans << endl;
    }
}
