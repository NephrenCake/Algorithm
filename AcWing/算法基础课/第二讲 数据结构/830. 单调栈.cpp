#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N], stk[N], tt = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (0 <= tt && a[stk[tt]] >= a[i]) tt--;
        if (0 <= tt) cout << a[stk[tt]] << " ";
        else cout << -1 << " ";
        stk[++tt] = i;
    }
}
