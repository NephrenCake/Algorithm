#include <iostream>

using namespace std;

const int N = 20;
int n, m, a[N], ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    // 枚举二进制状态i，每一位表示该状态集合是否取这个质数
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;  // t代表当前所有质数的乘积，cnt代表什么当前选法包含几个数
        for (int j = 0; j < m; j++)   // 遍历统计每个质数是否选上
            if (i >> j & 1) {
                if ((long long) t * a[j] > n) {  // n无法被该集合的乘积整除，该集合个数为0，跳过
                    t = -1;
                    break;
                }
                t = t * a[j];
                cnt++;
            }
        if (t != -1) {
            if (cnt & 1) ans += n / t;
            else ans -= n / t;
        }
    }
    cout << ans;
}
