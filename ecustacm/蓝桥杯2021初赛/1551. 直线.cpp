#include <bits/stdc++.h>

using namespace std;

// http://oj.ecustacm.cn/problem.php?id=1551

/**
 * 1. 用 exit(12); 二分找出错原因
 * 2. 注意精度 double
 */

#define PII pair<double, double>
#define x first
#define y second

int row = 21, col = 20;

vector<PII> ps;
unordered_set<string> res;

void record(const string& a, const string& b) {
    string t = a + b;
    if (res.find(t) != res.end())
        return;
    res.insert(t);
}

void make_line(PII p1, PII p2) {
    if (p1 == p2) return;
    if (p1.x == p2.x) {
        record("x=", to_string(p1.x));
        return;
    } else if (p1.y == p2.y) {
        record("y=", to_string(p1.y));
        return;
    }
    double a = (p1.y - p2.y) / (p1.x - p2.x);
    double b = p1.y - a * p1.x;
    record("a=" + to_string(a), "b=" + to_string(b));
    // exit(12);
}

int main() {
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            ps.emplace_back(i, j);

    for (auto p1 : ps)
        for (auto p2 : ps)
            make_line(p1, p2);

    // for (const auto& s : res)
    //     cout << s << endl;
    cout << res.size();
}
