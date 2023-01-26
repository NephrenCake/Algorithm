#include <iostream>

using namespace std;

int n, m;

int main() {
    while (cin >> n >> m) {
        // ��ͼ�ҹ���
        // 1. ��n == 1 && m == 1ʱ, ��������
        // 2. ��m == 1 || n == 1ʱ,����������
        // 3. ��n��mͬʱΪ����,����������
        // 4. ��m��n��ͬʱΪ����,���� m > 1 && n > 1,��������
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
//         if (nx == 1 && ny == 1 && sum == n * m && !(nx == fa_x && ny == fa_y)) {  // �߱鲢�ص����
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
