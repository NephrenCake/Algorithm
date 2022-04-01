#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1231/

/**
 * 19600101~20591231
 * 1. 判断是否合法
 * 2. 判断是否是给定的表示
 */

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int date1 = 19600101, date2 = 20591231;
int A, B, C;

bool check(int y, int m, int d) {
    if (m == 0 || m > 12) return false;
    if (d == 0 || m != 2 && d > days[m]) return false;

    if (m == 2) {
        int leap = y % 100 && y % 4 == 0 || y % 400 == 0;
        if (d > 28 + leap) return false;
    }
    return true;
}

bool check2(int y, int m, int d) {
    y = y % 100;
    return y == A && m == B && d == C ||
           m == A && d == B && y == C ||
           d == A && m == B && y == C;
}

int main() {
    scanf("%d/%d/%d", &A, &B, &C);

    for (int date = date1; date <= date2; ++date) {
        int y = date / 10000;
        int m = date % 10000 / 100;
        int d = date % 100;
        if (check2(y, m, d) && check(y, m, d))
            printf("%d-%02d-%02d\n", y, m, d);  // 02表示不足2位补0；03表示不足3位补0；
    }
}
