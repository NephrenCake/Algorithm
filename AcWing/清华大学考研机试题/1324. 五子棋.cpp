#include <iostream>

using namespace std;

const int N = 20;
int n, a[N][N];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string ans;
int w;

int look(int x, int y, int d, int tar) {
    int nx = x + dx[d], ny = y + dy[d];
    if (1 <= nx && nx <= n && 1 <= ny && ny <= n && a[nx][ny] == tar)
        return 1 + look(nx, ny, d, tar);
    return 0;
}

bool check(int x, int y, int tar) {
    for (int i = 0; i < 4; i++)
        if (look(x, y, i, tar) + 1 + look(x, y, i + 4, tar) >= 5)
            return true;
    return false;
}

int main() {
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        int val = i & 1 ? 1 : -1;
        a[x][y] = val;
        if (check(x, y, val)) {
            ans = i & 1 ? "A" : "B";
            w = i;
            cout << ans << " " << w;
            return 0;
        }
    }
    cout << "Tie";
}
