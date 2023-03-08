#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 11, M = 1 << N;
int n, k, st[M], used[M], ones[M];
long long ans, f[N][N * N][M];
vector<int> val[M];  // 存储上一行可能的合法状态

int count(int x) {
    int res = 0;
    while (x) res++, x -= x & (-x);
    return res;
}

int main() {
    cin >> n >> k;
    // 预处理每行的合法方案
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 1, isOK = 1;
        for (int j = 0; j < n; j++)
            if (i >> j & 1) {
                if (cnt == 0) {
                    isOK = 0;
                    break;
                } else cnt = 0;
            } else cnt++;
        st[i] = isOK;
        ones[i] = count(i);
    }
    // 预处理每行的合法状态下，前一行的合法状态
    for (int i = 0; i < 1 << n; i++)
        if (st[i]) {
            memset(used, 0, sizeof used);
            int mask = ((1 << n) - 1) ^ (i | (i << 1) | (i >> 1));  // 可以放置的位置
            for (int j = 0; j < 1 << n; j++) {
                int t = mask & j;
                if (st[t] && !used[t]) {
                    val[i].push_back(t);
                    used[t] = 1;
                }
            }
        }
    // dp
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int l = 0; l < 1 << n; l++)
                if (st[l] && j - ones[l] >= 0)
                    for (auto it: val[l])
                        f[i][j][l] += f[i - 1][j - ones[l]][it];
    for (int i = 0; i < 1 << n; i++)
        ans += f[n][k][i];
    cout << ans;
}
