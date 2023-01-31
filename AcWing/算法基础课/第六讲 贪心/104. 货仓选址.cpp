#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n, a[N];
long long ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++) ans += abs(a[i] - a[n / 2]);
    cout << ans;
}
