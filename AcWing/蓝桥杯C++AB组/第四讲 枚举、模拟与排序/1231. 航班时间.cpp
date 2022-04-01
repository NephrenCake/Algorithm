#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1233/

/**
 * 1. 真实时间 = [(end2 - begin2) + (end1 - begin1)] / 2
 * 2. 将所有时间转换成距离当天 00:00:00 的秒数
 * 3. 时间计算
 *          h = t / 3600
 *          m = t % 3600  / 60
 *          s = t % 60
 * 4. 用 getline
 */

string line;

inline int get_seconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int get_time() {
    getline(cin, line);
    if (line.back() != ')')
        line += " (+0)";

    int h1, m1, s1, h2, m2, s2, d;
    sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);

    return get_seconds(h2, m2, s2) - get_seconds(h1, m1, s1) + d * 24 * 3600;
}

int main() {
    int n;
    cin >> n;
    getline(cin, line);
    while (n--) {
        int t = (get_time() + get_time()) / 2;
        int h = t / 3600, m = t % 3600 / 60, s = t % 60;
        printf("%02d:%02d:%02d\n", h, m, s);
    }
}
