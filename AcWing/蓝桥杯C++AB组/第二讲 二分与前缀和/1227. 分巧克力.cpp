#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1229/

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

int get_num(int x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (h[i] / x) * (w[i] / x);
    }
    return sum;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i] >> w[i];

    int l = 1, r = N, m;
    while (l < r) {
        m = (l + r + 1) >> 1;
        if (k <= get_num(m)) l = m;  // 注意错误 必须是<=，不能是<
        else r = m - 1;
    }
    cout << r;
}
