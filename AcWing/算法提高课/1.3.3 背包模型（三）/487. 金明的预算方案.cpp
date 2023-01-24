#include <iostream>
#include <vector>

using namespace std;

#define v first
#define w second
typedef pair<int, int> PII;

const int N = 70, M = 32010;
int m, n, f[N][M];
PII fa[N];
vector<PII> son[N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!c) fa[i] = {a, a * b};
        else son[c].push_back({a, a * b});
    }

    for (int i = 1; i <= n; i++) {  // 前i个物品
        if (fa[i].v) {  // 如果第i个物品是主件
            // 01背包，先从主件开始放
            for (int j = fa[i].v; j <= m; j++)
                f[i][j] = max(f[i][j], f[i - 1][j - fa[i].v] + fa[i].w);

            // 因为push_back的下标是从0开始的，遍历的时候要注意
            // 这部分判断的是，放入当前的主件，对于这个主件的附件用01背包的方式去思考求解
            // 并且当前的f[i][j]一定是已经放入当前主件的情况
            for (int k = 0; k < son[i].size(); k++)
                for (int j = m; j >= son[i][k].v; j--)
                    // 放过主件以后，才能放附件，f为0的部分说明这部分放不进当前的主件
                    if (f[i][j - son[i][k].v] > 0)
                        f[i][j] = max(f[i][j], f[i][j - son[i][k].v] + son[i][k].w);
        }
        // 因为主件和附件要共同判断，但是在综合考虑之前，无法判断和前一个主件哪个更大
        // 注意i不是主件时，也要把状态传递下去
        for (int j = 0; j <= m; j++)
            f[i][j] = max(f[i][j], f[i - 1][j]);
    }

    cout << f[n][m] << endl;
}
