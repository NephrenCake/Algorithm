#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<long long> fib, s;

void dfs(int idx, int sum) {
    if (sum == n) {
        ans++;
        return;
    }
    if (idx == 0) return;

    if (sum + fib[idx] <= n)
        dfs(idx - 1, sum + fib[idx]);
    if (sum + s[idx - 1] >= n)
        dfs(idx - 1, sum);
}

int main() {
    cin >> n;
    fib.push_back(1);
    fib.push_back(1);
    s.push_back(1);
    s.push_back(2);
    for (int i = 2; fib[i - 1] <= 1e8 - fib[i - 2]; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]), s.push_back(fib[i] + s[i - 1]);

    dfs(fib.size() - 1, 0);
    cout << ans;
}
