#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
const int N = 300010;
int n, m, s[N];
vector<int> all;
vector<PII> a, q;

int find(int tar) {
    int l = 0, r = all.size() - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (tar <= all[m]) r = m;
        else l = m + 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;
    while (n--) {
        int x, c;
        cin >> x >> c;
        a.push_back({x, c});
        all.push_back(x);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        q.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    for (int i = 0; i < a.size(); i++)
        s[find(a[i].first)] += a[i].second;

    for (int i = 1; i <= all.size(); i++)
        s[i] += s[i - 1];

    for (int i = 0; i < q.size(); i++)
        cout << s[find(q[i].second)] - s[find(q[i].first) - 1] << endl;
}

