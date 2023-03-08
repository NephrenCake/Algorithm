#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 70;
int n, a[N], sum, len, used[N];

bool dfs(int cnt, int cur, int start){  // 第cnt组  cur当前组的已有长度  start表示第u组的枚举位置;
    if (cnt * len + cur == sum) return true;  // 如果总长度到达了,返回true
    if (cur == len) return dfs(cnt + 1, 0, n - 1);
    for (int i = start; i >= 0; i--)
        if (!used[i] && a[i] + cur <= len) {
            used[i] = 1;
            if (dfs(cnt, a[i] + cur, i - 1)) return true;
            used[i] = 0;
            // 如果放在一组的第一根并不能凑齐，或者放在一组的最后一根不能凑齐，就一定失败
            if (!cur || a[i] + cur == len) return false;
            while (i - 1 >= 0 && a[i - 1] == a[i]) i--;  // 去重
        }
    return false;
}

int main() {
    // 注意这题是每组数量刚好相同，所以dfs组别，前面几题不要求每组相同，所以dfs对象
    while (cin >> n, n) {
        memset(used, 0, sizeof used);
        sum = 0, len = 1;
        for (int i = 0; i < n; i++)  cin >> a[i], sum += a[i];
        sort(a, a + n);
        for (len = 1; len < sum; len++)
            if (sum % len == 0 && dfs(0, 0, n - 1))
                break;
        cout << len << endl;
    }
}
