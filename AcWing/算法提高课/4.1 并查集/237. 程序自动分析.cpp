#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, int> p;
vector<pair<int, pair<int, int>>> v;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t-- && cin >> n) {
        v.clear();
        bool flag = 1;
        for (int i = 1, a, b, c; i <= n; i++) {
            cin >> a >> b >> c;
            p[a] = a;
            p[b] = b;
            v.push_back({-c, {a, b}});
        }
        sort(v.begin(), v.end());
        for (auto it: v)
            if (it.first == -1) p[find(it.second.first)] = find(it.second.second);
            else if (find(it.second.first) == find(it.second.second)) flag = 0;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
