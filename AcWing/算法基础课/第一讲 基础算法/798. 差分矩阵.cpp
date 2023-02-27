#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q, t, x1, y1, x2, y2, c;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t, insert(i, j, i, j, t);
    while (q-- && cin >> x1 >> y1 >> x2 >> y2 >> c)
        insert(x1, y1, x2, y2, c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1], cout << a[i][j] << " ";
        cout << endl;
    }
}
