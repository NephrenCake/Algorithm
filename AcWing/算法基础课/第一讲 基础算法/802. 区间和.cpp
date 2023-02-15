#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m, all[3 * N], a[3 * N], cnt, x[N], c[N], l[N], r[N];  // all现数组下标->原数组下标 a现数组前缀和

int find(int tar) {
    int l = -1, r = cnt, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (all[m] < tar) l = m;
        else r = m - 1;
    }
    return r + 1;  // 找到第一个大于等于x的位置
}

int main()  {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i] >> c[i], all[++cnt] = x[i];  // 1. 记录输入信息和所有出现过的点
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i], all[++cnt] = l[i], all[++cnt] = r[i];
    sort(all + 1, all + 1 + cnt);  // 2. 存储下标从1开始，因为要前缀和
    for (int i = 0; i < n; i++) a[find(x[i])] += c[i];  // 3. 在离散化数组中存储值
    for (int i = 1; i <= cnt; i++) a[i] += a[i - 1];  // 4. 构造前缀和
    for (int i = 0; i < m; i++) cout << a[find(r[i])] - a[find(l[i]) - 1] << endl;
}
