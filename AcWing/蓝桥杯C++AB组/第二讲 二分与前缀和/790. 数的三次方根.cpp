#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/792/

int main() {
    double n;  // ˫����ȷ�������㹻
    cin >> n;

    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        // ע�� ��ĿҪ����6λ�������Լ�Ҫ�����λ
        // ע����� ��ļ�С�ģ���e-l
        double m = (l + r) / 2;
        if (n <= m * m * m) r = m;
        else l = m;
    }

    printf("%.6lf\n", l);  // �������l����r���У���Ϊ�����Ѿ���e-8
}
