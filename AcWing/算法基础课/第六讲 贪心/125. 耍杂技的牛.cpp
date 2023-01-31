#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;
int n, sum, ans = -0x3f3f3f3f;
pair<int, int> a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        a[i] = {w + s, w};
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int w = a[i].second, s = a[i].first - a[i].second;
        ans = max(ans, sum - s);
        sum += w;
    }
    cout << ans;
}
