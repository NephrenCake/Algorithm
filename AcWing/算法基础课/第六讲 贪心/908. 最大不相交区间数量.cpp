#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
int n, ans;
PII a[N], cur = {-2e9, -2e9};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (cur.second < a[i].first) {
            ans++;
            cur = a[i];
        } else
            cur.second = min(cur.second, a[i].second);
    cout << ans;
}
