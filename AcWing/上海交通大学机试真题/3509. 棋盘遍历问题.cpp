#include <iostream>

using namespace std;

int n, m;

int main() {
    while (cin >> n >> m) {
        // 画图找规律
        // 1. 当n == 1 && m == 1时, 满足题意
        // 2. 当m == 1 || n == 1时,不满足题意
        // 3. 当n和m同时为奇数,不满足题意
        // 4. 当m和n不同时为奇数,并且 m > 1 && n > 1,满足题意
        if (n == 1 && m == 1) cout << "Y" << endl;
        else if (n == 1 || m == 1) cout << "N" << endl;
        else if (n % 2 == 1 && m % 2 == 1) cout << "N" << endl;
        else cout << "Y" << endl;
    }
}

// #include <iostream>
// #include <cstring>
//
// using namespace std;
//
// const int N = 15;
// int n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
// bool used[N][N], flag;
//
// void dfs(int sum, int cur_x, int cur_y, int fa_x, int fa_y) {
//     // cout << cur_x << " " << cur_y << endl;
//     if (flag) return;
//
//     used[cur_x][cur_y] = true;
//     sum++;
//     for (int i = 0; i < 4; i++) {
//         int nx = cur_x + dx[i], ny = cur_y + dy[i];
//         if (nx == 1 && ny == 1 && sum == n * m && !(nx == fa_x && ny == fa_y)) {  // 走遍并回到起点
//             flag = true;
//             return;
//         }
//         if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !used[nx][ny])
//             dfs(sum, nx, ny, cur_x, cur_y);
//     }
//     used[cur_x][cur_y] = false;
// }
//
// int main() {
//     while (cin >> n >> m) {
//         memset(used, false, sizeof used);
//         flag = false;
//         dfs(0, 1, 1, 1, 1);
//         if (flag) cout << "Y" << endl;
//         else cout << "N" << endl;
//     }
// }
