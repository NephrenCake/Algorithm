#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = 0;
int N, M;
vector<vector<char>> ponds;
vector<vector<bool>> visited;
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && ponds[nx][ny] == 'W')
            dfs(nx, ny);
    }
}

int main() {
    cin >> N >> M;
    ponds = vector<vector<char>>(N, vector<char>(M, '.'));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    char temp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> temp;
            if (temp == '.')
                continue;
            ponds[i][j] = temp;
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!visited[i][j] && ponds[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
    cout << ans;
}