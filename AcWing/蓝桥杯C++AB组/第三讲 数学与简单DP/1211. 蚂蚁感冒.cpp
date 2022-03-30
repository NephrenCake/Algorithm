#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1213/

/**
 * 性质：
 * 1. 掉头等价于穿过，灵魂互换
 * 第一个蚂蚁向右走的情况:
 * 1. 右边向左走的，必然被感染
 * 2. 右边向右走，必然不会被感染
 * 3. 左边向左走，必然不会被感染
 * 4. 左边向右走:
 *      (1)右边存在向左走，则必然被感染
 *      (2)右边不存在向左走，则必然不会被感染
 */

const int N = 55;

int n;
int x[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int l2r = 0, r2l = 0;  // 分别表示左边向右走的蚂蚁数量，和右边向左走的蚂蚁数量
    for (int i = 0; i < n; i++)
        if (abs(x[i]) < abs(x[0]) && x[i] > 0)
            l2r++;
        else if (abs(x[i]) > abs(x[0]) && x[i] < 0)
            r2l++;

    if (x[0] > 0 && r2l == 0 || x[0] < 0 && l2r == 0)
        cout << 1 << endl;
    else
        cout << l2r + r2l + 1 << endl;
}
