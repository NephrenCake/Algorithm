#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a, stk[N], tt = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (0 <= tt && stk[tt] >= a) tt--;
        stk[++tt] = a;
        if (tt - 1 != -1) cout << stk[tt - 1] << " ";
        else cout << -1 << " ";
    }
}
