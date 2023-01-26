#include <iostream>

using namespace std;

const int N = 10010;
string a, b;
int f[N], res;

bool check(char ch) {
    return ch < '0' || ch > '9';
}

int main() {
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 1; i < a.size(); i++)
        for (int j = b.size() - 1; j; j--) {
            // f[i][j] 第一个字符串以a[i]结尾，第二个字符串以b[j]结尾，的最长公共子串的长度
            if (a[i] == b[j] && check(a[i]) && check(b[j]))
                f[j] = f[j - 1] + 1;
            else
                f[j] = 0;  // 将二维优化到一维时，一定要手动处理非连续部分的dp值，否则会自动转移状态
            res = max(res, f[j]);
        }
    cout << res;
}
