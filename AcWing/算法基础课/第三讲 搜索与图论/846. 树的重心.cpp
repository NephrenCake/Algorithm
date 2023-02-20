#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> v[N];
int n, ans = 0x3f3f3f3f;

int dfs(int idx, int fa) {
    int maxVal = 0, sum = 1;
    for (auto ne: v[idx])
        if (ne != fa) {
            int ch = dfs(ne, idx);
            maxVal = max(maxVal, ch);
            sum += ch;
        }
    maxVal = max(maxVal, n - sum);
    ans = min(ans, maxVal);
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 1);
    cout << ans;
}
