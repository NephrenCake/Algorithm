#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1239/

/**
 * 1. ģ�� 10^18 -> TLE
 * 2. ÿ����һ���� 10^9 -> TLE
 * 3. �ҹ��� O(1)
 */

int x, y;

int main() {
    cin >> x >> y;

    if (abs(x) <= y) {  // �Ϸ�
        int n = y;
        cout << (long long) (2 * n - 1) * (2 * n) + x - (-n) << endl;
    } else if (abs(y) <= x) {  // �ұ�
        int n = x;
        cout << (long long) (2 * n) * (2 * n) + n - y << endl;
    } else if (abs(x) < -y) {  // �·�
        int n = abs(y);
        cout << (long long) (2 * n) * (2 * n + 1) + n - x << endl;
    } else {  // ���
        int n = abs(x);
        cout << (long long) (2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
    }
}
