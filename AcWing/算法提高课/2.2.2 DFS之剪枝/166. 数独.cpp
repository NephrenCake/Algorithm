#include<iostream>
#include<algorithm>

using namespace std;

const int N = 9, M = 1 << N;
int ones[M], log2[M];  // ones记录不同状态中多少个1，log2返回1的位号
int rows[N], cols[N], cell[3][3];  // col每列分别存了哪些数  row每行分别存了哪些数  cell每个九宫格存了哪些数
string s;

int lowbit(int x) {
    return x & -x;
}

int get_ones(int x) {
    int cnt = 0;
    while (x) cnt++, x -= lowbit(x);
    return cnt;
}

void draw(int x, int y, int t, bool set_num) {
    s[x * N + y] = set_num ? '1' + t : '.';  // t为0-8
    int v = set_num ? -(1 << t) : 1 << t;  // 在状态中，1表示没放数，0表示已放数
    rows[x] += v;
    cols[y] += v;
    cell[x / 3][y / 3] += v;
}

int get_state(int x, int y) {  // x行y列处的状态，该格子可以填哪些数字
    return rows[x] & cols[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (cnt == 0) return true;
    int minv = 10, x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (s[i * N + j] == '.') {
                int it = ones[get_state(i, j)];  // 选择填写可选项最少的
                if (it < minv) {
                    minv = it;
                    x = i, y = j;
                }
            }
    for (int i = get_state(x, y); i; i -= lowbit(i)) {
        int t = log2[lowbit(i)];  //这个t就是要填充的数字
        draw(x, y, t, true);  //填这个数字
        if (dfs(cnt - 1)) return true;  //这次填充成功，则返回
        draw(x, y, t, false);  //失败则回溯
    }
    return false;
}

int init() {
    // cnt表示还剩多少个数字没有填  初始状态state的9位二进制全是1
    int cnt = 0;
    // 如果row[0] = 111111111 代表第一行可以填9个数, 这里行号是0-8
    for (int i = 0; i < N; i++) rows[i] = cols[i] = cell[i / 3][i % 3] = (1 << N) - 1;
    for (int i = 0, k = 0; i < N; i++)
        for (int j = 0; j < N; j++, k++)
            if (s[k] == '.') cnt++;  // 需要填数字
            else draw(i, j, s[k] - '1', true);
    return cnt;
}

int main() {
    for (int i = 0; i < N; i++) log2[1 << i] = i;
    for (int i = 0; i < M; i++) ones[i] = get_ones(i);
    while (cin >> s, s != "end") {
        int k = init();
        dfs(k);
        cout << s << endl;
    }
}
