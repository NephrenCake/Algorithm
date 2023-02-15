#include <iostream>

using namespace std;

const int N = 100010;
int n, a[N], q[N], len;  // 长度为i结尾的子序列的末位最小是多少

int find(int tar) {
    int l = 0, r = len, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (q[m] < tar) l = m;
        else r = m - 1;
    }
    return r + 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int idx = find(a[i]);
        // cout << idx << " ";
        len = max(len, idx);
        q[idx] = a[i];
    }
    cout << len;
}
