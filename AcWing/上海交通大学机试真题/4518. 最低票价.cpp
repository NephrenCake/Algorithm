#include <iostream>

using namespace std;

const int N = 366;
int n, days[N], costs[3], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> days[i];
    for (int i = 0; i < 3; i++) cin >> costs[i];

    // f[i] 前i天，所花费的最低费用
    // 1天通行证 | 7天通行证 | 30天通行证
    // if 需要花钱
    //     f[i] = min(f[max(i - 1, 0)] + cost[0], f[max(i - 7, 0)] + cost[1], f[max(0, i - 30)] + cost[2])
    for (int i = 1, j = 1; i <= 365; i++) {
        f[i] = f[i - 1];
        if (i == days[j]) {
            f[i] += costs[0];
            f[i] = min(f[i], f[max(i - 7, 0)] + costs[1]);
            f[i] = min(f[i], f[max(i - 30, 0)] + costs[2]);
            j++;
        }
    }
    cout << f[365];
}
