#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N];
long long p, q;

int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++)
        cin >> t, a[i] += t, a[i + 1] -= t;
    for (int i = 2; i <= n; i++)
        if (a[i] > 0) p += a[i];
        else q -= a[i];

    cout << max(p, q) << endl;
    cout << abs(p - q) + 1 << endl;
}
