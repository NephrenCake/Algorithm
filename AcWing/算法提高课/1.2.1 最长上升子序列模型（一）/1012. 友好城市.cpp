#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n, a[N], f[N];

int main() {
    for (int i = 0; i < N; i++) a[i] = -1;
    cin >> n;
    while (n--) {
        int p, q;
        cin >> p >> q;
        a[p] = q;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == -1) continue;
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] == -1) continue;
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }

    cout << ans;
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 10010;
int n, f[N];
PII a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i].second > a[j].second)
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}

 */
