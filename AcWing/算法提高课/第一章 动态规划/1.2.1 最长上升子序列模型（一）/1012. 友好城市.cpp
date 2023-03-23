#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10010;
int n, b[N], val[N], f[N], ans;
typedef pair<int, int> PII;
vector<PII> a;

int main() {
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < (int) a.size(); i++)
        b[i + 1] = a[i].second;

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (b[j] < b[i])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans;
}
