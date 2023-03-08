#include <iostream>
#include <vector>

using namespace std;

const int N = 11;
int n, num[N], ans = 0x3f3f3f3f;
vector<int> g[N];

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

bool check(vector<int> &v, int x) {
    for (auto it: v)
        if (gcd(it, x) > 1)
            return false;
    return true;
}

void dfs(int idx, int cnt) {
    if (cnt > ans) return;
    if (idx == n) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++)
        if (check(g[i], num[idx])) {
            g[i].push_back(num[idx]);
            dfs(idx + 1, cnt);
            g[i].pop_back();
        }
    g[cnt + 1].push_back(num[idx]);
    dfs(idx + 1, cnt + 1);
    g[cnt + 1].pop_back();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    dfs(0, 1);
    cout << ans;
}
