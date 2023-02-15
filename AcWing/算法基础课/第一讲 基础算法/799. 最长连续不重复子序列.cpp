#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], used[N], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0, j = 0; i < n && j < n; ) {
        while (j < n && !used[a[j]]) used[a[j++]] = 1;
        ans = max(ans, j - i);
        used[a[i++]] = 0;
    }
    cout << ans;
}
