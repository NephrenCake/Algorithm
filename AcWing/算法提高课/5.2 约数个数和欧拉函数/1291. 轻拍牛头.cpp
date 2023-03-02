#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, a[N], maxv, ans[N], cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        maxv = max(maxv, a[i]);
    }

    for (int i = 1; i <= maxv; i++)
        if (cnt[i])
            for (int j = i; j <= maxv; j += i)
                ans[j] += cnt[i];
    for (int i = 1; i <= n; i++)
        cout << ans[a[i]] - 1 << endl;
}
