#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/468/

/**
 * 1. ö�ٻ���
 * 2. �ж��Ƿ��ڷ�Χ��
 * 3. ���ж������Ƿ�Ϸ�
 *
 * �����жϱ��ʽ�����ܱ� 100 �������� 4 ���������߱� 400 ����
 *              y % 100 && y % 4 == 0 || y % 400 == 0
 */

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date) {
    int y = date / 10000;
    int m = date % 10000 / 100;
    int d = date % 100;

    if (m == 0 || m > 12) return false;
    if (d == 0 || m != 2 && d > days[m]) return false;

    if (m == 2) {
        int leap = y % 100 && y % 4 == 0 || y % 400 == 0;
        if (d > 28 + leap) return false;
    }
    return true;
}

int main() {
    int date1, date2;
    cin >> date1 >> date2;

    int ans = 0;
    for (int i = 1000; i < 10000; i++) {
        int date = i, x = i;
        for (int j = 0; j < 4; j++)
            date = date * 10 + x % 10, x /= 10;

        if (date1 <= date && date <= date2 && check(date))
            ans++;
    }
    cout << ans;
}
