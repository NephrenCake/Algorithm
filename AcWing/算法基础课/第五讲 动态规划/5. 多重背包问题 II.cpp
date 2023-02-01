#include<iostream>

using namespace std;

const int N = 12010, M = 2010;

int n, m, v[N], w[N], f[M];

int main() {
    cin >> n >> m;
    int cnt = 0;  // 将n种物品打包成cnt个组，每组是一个选择方案
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        for (int k = 1; k <= s; k *= 2) {  // 分别打包成1、2、4……个位一组
            cnt++;  // 组别先增加
            v[cnt] = a * k;  // 该打包组的体积
            w[cnt] = b * k;  // 该打包组的价值
            s -= k;  // s要减小
        }
        if (s > 0) {  // 剩余的一组
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    // 枚举次数n由个数变成组数。多重背包转为01背包
    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m];
}
