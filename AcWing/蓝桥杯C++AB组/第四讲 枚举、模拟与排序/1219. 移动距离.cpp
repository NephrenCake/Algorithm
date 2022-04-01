#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1221/

/**
 * 1，先将所有序号-1，好处是可以方便求行号：n/w、m/w
 * 2. 正常的列号：n%w、m%w；翻转列号：if n/w 奇: w-1-n%w
 */

int w, m, n;

int main() {
    cin >> w >> m >> n;
    m--, n--;
    int x1, y1, x2, y2;
    x1 = m / w;
    x2 = n / w;
    y1 = m % w;
    y2 = n % w;
    if (x1 % 2) y1 = w - 1 - y1;
    if (x2 % 2) y2 = w - 1 - y2;

    cout << abs(x1 - x2) + abs(y1 - y2);
}
