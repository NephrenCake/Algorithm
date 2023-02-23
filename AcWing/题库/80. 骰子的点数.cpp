class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int> ans;
        int f[n + 1][6 * n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++)  // 抛i次
            for (int j = i; j <= 6 * i; j++) {  // 凑成点数j
                if (i == 1) f[i][j] = 1;
                else
                    for (int k = 1; k <= 6; k++)  // 枚举策略
                        if (j - k >= 1)
                            f[i][j] += f[i - 1][j - k];
                if (i == n)
                    ans.push_back(f[i][j]);
            }
        return ans;
    }
};
