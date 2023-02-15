#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
int n, k;
PII a[N], ans[N], cur = {-0x3f3f3f3f, -0x3f3f3f3f};

int main() {
    cin >> n;
    for (int i = 0, l, r; i < n; i++) cin >> l >> r, a[i] = {l, r};
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        if (cur.second < a[i].first) {
            cur = a[i];
            ans[k++] = cur;
        } else
            cur.second = max(cur.second, a[i].second);
    cout << k;
}
