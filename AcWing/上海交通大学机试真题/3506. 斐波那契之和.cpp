#include <iostream>

using namespace std;

int fib[50] = {1, 1}, n = 2;
long long sum[50] = {1, 2};
int ans, tar;

void dfs(int cur, int idx) {
    if (cur > tar) return;
    if (idx == 0) {
        if (cur == tar) ans++;
        return;
    }

    dfs(cur + fib[idx], idx - 1);
    if (cur + sum[idx - 1] >= tar)
        dfs(cur, idx - 1);
}

int main() {
    while (fib[n - 1] < 100000000) {
        fib[n] = fib[n - 1] + fib[n - 2];
        sum[n] = sum[n - 1] + fib[n];
        n++;
    }

    cin >> tar;
    dfs(0, n - 1);
    cout << ans;
}
