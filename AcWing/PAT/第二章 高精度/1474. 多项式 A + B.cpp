#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1476/

const int N = 1010;

int n, m, t, top, cnt;
double a[N], b[N], v, ans[N];

int main() {
    cin >> n;
    while (n--) {
        cin >> t >> v;
        a[t] = v;
        top = max(t, top);
    }
    cin >> m;
    while (m--) {
        cin >> t >> v;
        b[t] = v;
        top = max(t, top);
    }

    for (int i = top; i >= 0; i--)
        if (a[i] != 0 || b[i] != 0) {
            ans[i] = a[i] + b[i];
            if (ans[i] != 0) cnt++;
        }

    cout << cnt;
    for (int i = top; i >= 0; i--)
        if (ans[i] != 0)
            printf(" %d %.1lf", i, ans[i]);
}
