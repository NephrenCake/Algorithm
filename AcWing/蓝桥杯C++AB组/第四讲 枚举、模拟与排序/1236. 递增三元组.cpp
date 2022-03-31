#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1212/

/**
 * 暴力：三重循环找 A < B < C O(3)
 * 优化：由数据可知时间复杂度应当 <= nlog(n)，即至多枚举一个数组
 *      故，可以先固定 B，再二分 A、C
 *      在 A 中有多少个小于 B；在 C 中有多少个大于 B；
 * 方法：
 *      1. 前缀和
 *      2. 二分
 *      3. 双指针
 */

/**
 * 解1 二分
 */

const int N = 1e5 + 10;

int n;
int A[N], B[N], C[N];
int num_a, num_c;
int l, r, m;

int find_num(int t) {
    // 要考虑到无解的情况，即一个数完全大于另一个数组所有数
    // 先二分A
    l = -1, r = n - 1;
    while (l < r) {
        m = (l + r + 1) >> 1;
        if (A[m] < t) l = m;
        else r = m - 1;
    }
    num_a = r + 1;  // 注意错误，要小于t
    // 再二分C
    l = 0, r = n;
    while (l < r) {
        m = (l + r) >> 1;
        if (t < C[m]) r = m;
        else l = m + 1;
    }
    num_c = n - r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);
    for (int i = 0; i < n; i++) scanf("%d", &C[i]);
    sort(A, A + n);
    sort(B, B + n);
    sort(C, C + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        find_num(B[i]);
        ans += (long long) num_a * num_c;
    }
    cout << ans;
}

/**
 * 解2 前缀和
 *      cnt[i] 表示 i 这个数在 A 中出现多少次
 *      S[i] 表示 0~i 在 A 中一共出现多少次
 *      由于前缀和的时间复杂度为 0(数值范围)，且这题数值范围和数据范围相同，所以可以用前缀和
 */

/*
const int N = 1e5 + 10;

int n;
long long ans;  // 注意错误 会爆int
int A[N], B[N], C[N];
int As[N], Cs[N];  // as[i]表示在A[]中有多少个数小于b[i]
int cnt[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]), A[i]++;
    for (int i = 0; i < n; i++) scanf("%d", &B[i]), B[i]++;
    for (int i = 0; i < n; i++) scanf("%d", &C[i]), C[i]++;  // 注意偏移

    // 找A
    for (int i = 0; i < n; i++) cnt[A[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) As[i] = s[B[i] - 1];

    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);  // 清空
    // 找C
    for (int i = 0; i < n; i++) cnt[C[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) Cs[i] = s[N - 1] - s[B[i]];  // 注意错误 是大于b

    // 找答案
    for (int i = 0; i < n; i++) ans += (long long)As[i] * Cs[i];  // 注意错误 会爆int
    cout << ans;
}
*/