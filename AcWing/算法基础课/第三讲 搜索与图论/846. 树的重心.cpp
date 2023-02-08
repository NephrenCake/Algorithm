#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, a, b, ans = 0x3f3f3f3f;
vector<int> v[N];
bool used[N];

int dfs(int cur) {
    used[cur] = true;
    int sum = 1, res = 0;
    for (int i : v[cur]) {
        if (!used[i]) {
            int t = dfs(i);
            res = max(res, t);
            sum += t;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    cin >> n;
    while (cin >> a >> b)
        v[a].push_back(b), v[b].push_back(a);

    dfs(1);
    cout << ans;
}
