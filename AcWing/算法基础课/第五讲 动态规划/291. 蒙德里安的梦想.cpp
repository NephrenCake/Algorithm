#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 12, M = 1 << N;
int n, m, st[M];  // 存储每种状态是否有效，如果奇数个0是无效状态，如果是偶数个零置为true。
long long f[N][M];
vector<int> pre[M];  // 选出从中遍历的合法状态

int main() {
    while (cin >> n >> m, n || m) {
        // 预处理1：对于一列可能的每种状态，先预处理每列不能有奇数个连续的0
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0, flag = 1;  // 记录连续的0的个数
            for (int j = 0; j < n; j++)  // 从上到下遍历这一列
                if (i >> j & 1) {  // i状态的第j位为1
                    if (cnt & 1) {  // 若前面连续的0的个数是奇数则不合法
                        flag = 0;
                        break;
                    } else cnt = 0;  // 计数器清零。其实清不清零没有影响
                } else cnt++;  // 否则连续0，计数器++。
            if (cnt & 1) flag = 0;  // 奇数个连续的0仍然不合法
            st[i] = flag;  // 状态i是否有奇数个连续的0的情况,输入到数组st中
        }
        // 预处理2：第i-2列伸出来的和第i-1列伸出去的是否冲突
        for (int i = 0; i < (1 << n); i++) {  // 对于第i列的所有状态
            pre[i].clear();  // 清空上次询问
            for (int j = 0; j < (1 << n); j++)  // 对于第i-1列所有状态
                if ((i & j) == 0 && st[i | j])
                    // 第i-2列伸出来的 和第i-1列伸出来的不冲突(不在同一行)
                    // st[i | j] 表示第i-1列是否合法
                    pre[i].push_back(j);  // 表示第i列前一列真正可行的状态j
        }
        // dp
        memset(f, 0, sizeof f);  // f[i][j] 前i列都摆好，最后以状态j伸出到i+1列，的方案数
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)  // 遍历每一列:第i列合法范围是(0~m-1列)
            for (int j = 0; j < (1 << n); j++)  // 遍历当前列（第i列）所有状态j
                for (auto k: pre[j])  // 遍历第i-1列的状态k，如果“真正”可行，就转移
                    f[i][j] += f[i - 1][k];  // 当前列的方案数就等于之前的第i-1列所有状态k的累加。
        cout << f[m][0] << endl;  // 表示 前m列都处理完，并且第m+1列没有伸出来的所有方案数。即整个棋盘处理完的方案数
    }
}
