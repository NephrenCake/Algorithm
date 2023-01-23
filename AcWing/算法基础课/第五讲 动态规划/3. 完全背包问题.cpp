#include <iostream>
using namespace std;

const int N = 1010;
int n, m, v, w, f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = 1; j <= m; j++)
            if (j - v >= 0)
                f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m];
}
