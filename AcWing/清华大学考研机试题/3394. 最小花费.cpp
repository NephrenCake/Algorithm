#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
int l[3], c[3], A, B, n, a[N], f[N];

int main() {
    for (int i = 0; i < 3; i++) cin >> l[i];
    for (int i = 0; i < 3; i++) cin >> c[i];
    cin >> A >> B >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];

    // f[i]  从A节点开始走到i节点需要的最小花费
    memset(f, 0x3f, sizeof f);
    f[A] = 0;
    for (int i = A + 1; i <= B; i++) {  // 节点
        for (int j = 0; j < 3; j++) { // 方案
            int x = a[i] - l[j];  // 可以到达的最远距离
            // printf("j=%d x=%d a[i-1]=%d\n", j, x, a[i-1]);
            for (int k = i - 1; k >= A && x <= a[k]; k--) {
                // printf("j=%d k=%d x=%d a[k]=%d \n", j, k, x, a[k]);
                f[i] = min(f[i], f[k] + c[j]);
            }
        }
        // printf("f[%d] = %d\n", i, f[i]);
    }
    cout << f[B];
}
