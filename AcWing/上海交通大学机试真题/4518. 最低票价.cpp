#include <iostream>
#include <cstring>

using namespace std;

const int N = 370;
int n, days[N], cost[3], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> days[i];
    cin >> cost[0] >> cost[1] >> cost[2];

    // f[i] 前i天，所花费的最低费用
    // 1天通行证 | 7天通行证 | 30天通行证
    // if 需要花钱
    //     f[i] = min(f[max(i - 1, 0)] + cost[0], f[max(i - 7, 0)] + cost[1], f[max(0, i - 30)] + cost[2])
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1, t = 1; i <= 365; i++) {
        if (i < days[t] || t > n)  // 还没有到旅行的日子 | 计划已经结束
            f[i] = f[i - 1];  // 将状态传递下去
        else {
            f[i] = min(f[max(i - 1, 0)] + cost[0], min(f[max(i - 7, 0)] + cost[1], f[max(0, i - 30)] + cost[2]));
            t++;
        }
    }
    cout << f[365];
}
