#include <iostream>

using namespace std;

const int N = 1000010;
int n, a[N], b[N];
int q[N], len;

// 4. 二分优化（贪心）
int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);  // cin 超时
        a[t] = i;
    }
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        b[i] = a[t];
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        int l = 0, r = len, m, tar = b[i];
        while (l < r) {
            m = (l + r + 1) / 2;
            if (q[m] < tar) l = m;
            else r = m - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = tar;
    }
    cout << len;
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 1000010;
// int n, a[N], b[N], f[N], res;
//
// // 3. 根据第一个序列中的所有元素均不重复，将“两个字符串的最长公共子序列长度”转化为“第二个字符串的最长上升子序列长度”
// // Time Limit Exceeded
// int main() {
//     cin >> n;
//     for (int i = 1, t; i <= n; i++) {
//         cin >> t;
//         a[t] = i;  // 交换值和下标。则两者的公共子序列，必定满足a[b[k]]严格单调递增
//     }
//     for (int i = 1, t; i <= n; i++) {
//         cin >> t;
//         b[i] = a[t];
//     }
//
//     for (int i = 1; i <= n; i++) { // b中前i个数字并且以b[i]结尾的最长上升的子序列
//         if (b[i] == 0) continue;  // 如果为0则表示不存在，则以b[i]结尾的最长上升的子序列也就不存在
//         f[i] = 1;
//         for (int j = 1; j < i; j++) {
//             if (b[j] < b[i])
//                 f[i] = max(f[i], f[j] + 1);
//             res = max(res, f[i]);
//         }
//     }
//     cout << res;
// }

// #include <iostream>
// #include <cstring>
//
// using namespace std;
//
// const int N = 1000010;
// int n, a[N], b[N], f[N], g[N];
//
// // 1. 二维最长公共子序列 Memory Limit Exceeded
// // 2. 滚动数组优化最长公共子序列 Time Limit Exceeded
// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> b[i];
//
//     for (int i = 1; i <= n; i++) {
//         memcpy(g, f, sizeof f);
//         for (int j = 1; j <= n; j++) {
//             f[j] = max(g[j], f[j - 1]);
//             if (a[i] == b[j])
//                 f[j] = max(f[j], g[j - 1] + 1);
//         }
//     }
//     cout << f[n];
// }
