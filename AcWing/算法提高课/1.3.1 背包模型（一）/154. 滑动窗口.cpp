#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int n, m, a[N];

typedef pair<int, int> PII;
priority_queue<PII> p, q;
PII res[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i < m) {
            p.push({a[i], i});
            q.push({-a[i], i});
        }
    }

    for (int i = m; i <= n; i++) {
        p.push({a[i], i});
        q.push({-a[i], i});
        while (p.top().second < i - m + 1) p.pop();
        while (q.top().second < i - m + 1) q.pop();
        res[i] = {p.top().first, -q.top().first};
    }
    for (int i = m; i <= n; i++) cout << res[i].second << " ";
    cout << endl;
    for (int i = m; i <= n; i++) cout << res[i].first << " ";
}
