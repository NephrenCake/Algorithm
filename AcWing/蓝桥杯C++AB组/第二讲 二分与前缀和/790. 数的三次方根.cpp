#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/792/

int main() {
    double n;  // 双精度确保精度足够
    cin >> n;

    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        // 注意 题目要求保留6位，我们自己要多加两位
        // 注意错误 大的减小的，是e-l
        double m = (l + r) / 2;
        if (n <= m * m * m) r = m;
        else l = m;
    }

    printf("%.6lf\n", l);  // 这里输出l或者r都行，因为精度已经是e-8
}
