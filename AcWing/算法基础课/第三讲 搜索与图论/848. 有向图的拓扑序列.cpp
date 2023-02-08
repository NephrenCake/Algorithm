#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, d[N];
vector<int> v[N], ans;
int q[N], hh = 0, tt = -1;

int main() {
    cin >> n >> m;
    while (cin >> a >> b) v[a].push_back(b), d[b]++;

    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q[++tt] = i;
    while (hh <= tt) {
        int cur = q[hh++];
        ans.push_back(cur);
        for (int i: v[cur]) {
            d[i]--;
            if (d[i] == 0)
                q[++tt] = i;
        }
    }
    if (ans.size() == n)
        for (int i: ans)
            cout << i << " ";
    else
        cout << -1;
}
