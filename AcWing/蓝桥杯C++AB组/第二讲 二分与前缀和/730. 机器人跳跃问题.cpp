#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/732/

/**
 * 转换状态
 * 1. if h > e, then e - (h - e) = 2e - h;
 * 2. if h <= e, then e + (e - h) = 2e - h;
 *
 * ☆ 数据指数级上升，即使是long long也包不住
 *    if e > max_h, then f(x) = 2e - h
 *                            = e + e - h
 *                            >= e + max_h - h
 *                            >= e
 *                       f(x) ↑
 *    只要大于最高高度，就一定会严格递增，不用再算了
 */

const int N = 1e5 + 10;

int h[N];
int n, max_;

bool is_able(long long e) {
    for (int i = 1; i <= n; i++) {
        // 注意错误 爆int了（悲
        // 注意错误 爆long long了（大悲
        // 改进方法：只要大于最高高度，就一定会严格递增，不用再算了
        e = 2 * e - h[i];
        if (e < 0)
            return false;
        if (e > max_)
            return true;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        max_ = max(max_, h[i]);
    }

    int l = 1, r = N, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (is_able(m)) r = m;
        else l = m + 1;
    }

    cout << r;
}
