#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int N = 15;
int n, a[N], used[N], ans;
unordered_set<int> sq;

void dfs(int idx, int last) {
    if (idx == n + 1) {
        ans++;
        return;
    }

    unordered_set<int> u;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && sq.find(a[i] + last) != sq.end() && u.find(a[i]) == u.end()) {
            u.insert(a[i]);
            used[i] = 1;
            dfs(idx + 1, a[i]);
            used[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i <= 2e9 / i; i++) sq.insert(i * i);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_set<int> u;
    for (int i = 1; i <= n; i++)
        if (u.find(a[i]) == u.end()) {
            u.insert(a[i]);
            used[i] = 1;
            dfs(2, a[i]);
            used[i] = 0;
        }
    cout << ans;
}
