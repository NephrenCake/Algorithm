#include <iostream>

using namespace std;

int dfs(int n, int m) {
    if (n == m) return 1;
    if (n == 0 || m == 0) return 0;
    if (n > m)
        return n / m + dfs(n % m, m);
    return m / n + dfs(n, m % n);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << dfs(n, m);
}
