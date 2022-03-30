#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/732/

/**
 * ת��״̬
 * 1. if h > e, then e - (h - e) = 2e - h;
 * 2. if h <= e, then e + (e - h) = 2e - h;
 *
 * �� ����ָ������������ʹ��long longҲ����ס
 *    if e > max_h, then f(x) = 2e - h
 *                            = e + e - h
 *                            >= e + max_h - h
 *                            >= e
 *                       f(x) ��
 *    ֻҪ������߸߶ȣ���һ�����ϸ����������������
 */

const int N = 1e5 + 10;

int h[N];
int n, max_;

bool is_able(long long e) {
    for (int i = 1; i <= n; i++) {
        // ע����� ��int�ˣ���
        // ע����� ��long long�ˣ���
        // �Ľ�������ֻҪ������߸߶ȣ���һ�����ϸ����������������
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
