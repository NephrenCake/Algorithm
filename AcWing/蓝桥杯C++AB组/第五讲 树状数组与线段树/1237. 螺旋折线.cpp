#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1239/

/**
 * 1. 模拟 10^18 -> TLE
 * 2. 每次走一条边 10^9 -> TLE
 * 3. 找规律 O(1)
 */

int x, y;

int main() {
    cin >> x >> y;

    if (abs(x) <= y) {  // 上方
        int n = y;
        cout << (long long) (2 * n - 1) * (2 * n) + x - (-n) << endl;
    } else if (abs(y) <= x) {  // 右边
        int n = x;
        cout << (long long) (2 * n) * (2 * n) + n - y << endl;
    } else if (abs(x) < -y) {  // 下方
        int n = abs(y);
        cout << (long long) (2 * n) * (2 * n + 1) + n - x << endl;
    } else {  // 左边
        int n = abs(x);
        cout << (long long) (2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
    }
}
