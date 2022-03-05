#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int m, n, count_;
vector<vector<char>> grids;
vector<vector<bool>> visited;
int dx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int dy[] = {0, -1, 1, 0, -1, 1, 1, -1};


void dfs(int x, int y) {
    if (visited[x][y])
        return;
    visited[x][y] = true;
    for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grids[nx][ny] == '@' && !visited[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    while (true) {
        cin >> m >> n;
        if (m == 0 || n == 0)
            return 0;
        grids = vector<vector<char>>(m, vector<char>(n, '*'));
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grids[i][j];
        count_ = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grids[i][j] == '@' && !visited[i][j]) {
                    count_++;
                    dfs(i, j);
                }
        cout << count_ << endl;
    }
}