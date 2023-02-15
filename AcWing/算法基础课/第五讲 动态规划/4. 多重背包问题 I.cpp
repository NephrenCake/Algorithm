#include <iostream>

using namespace std;

const int N = 110, M = 110;
int n, m, v, w, s, f[M];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int j = m; j; j--)
            for (int k = 0; k <= s; k++)
                if (j - k * v >= 0)
                    f[j] = max(f[j], f[j - k * v] + k * w);
    }
    cout << f[m];
}
