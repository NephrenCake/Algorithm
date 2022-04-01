#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1221/

/**
 * 1���Ƚ��������-1���ô��ǿ��Է������кţ�n/w��m/w
 * 2. �������кţ�n%w��m%w����ת�кţ�if n/w ��: w-1-n%w
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
