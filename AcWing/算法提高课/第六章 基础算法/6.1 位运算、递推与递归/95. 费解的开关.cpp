#include <iostream>
#include <cstring>

using namespace std;

string g[5], bg[5];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void turn(int x, int y) {
    bg[x][y] = bg[x][y] == '0' ? '1' : '0';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx <= 4 && 0 <= ny && ny <= 4)
            bg[nx][ny] = bg[nx][ny] == '0' ? '1' : '0';
    }
}

int forward(int op) {
    // 备份
    for (int i = 0; i < 5; i++)
        bg[i] = g[i];
    // 第一行的操作状态
    int res = 0;
    for (int i = 0; i <= 4; i++)
        if (op >> i & 1)
            turn(0, i), res++;
    // 递推
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 4; j++)
            if (bg[i][j] == '0') {
                turn(i + 1, j);
                res++;
                // pr();
                if (res > 6) return 0x3f3f3f3f;
            }
    // 检查最后一行
    for (int j = 0; j <= 4; j++)
        if (bg[4][j] == '0')
            return 0x3f3f3f3f;
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 5; i++)
            cin >> g[i];

        int ans = 0x3f3f3f3f;
        for (int i = 0; i < (1 << 5); i++)
            ans = min(ans, forward(i));
        if (ans != 0x3f3f3f3f) cout << ans <<endl;
        else cout << -1 << endl;
    }
}
