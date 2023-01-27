#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q, a[N][N], b[N][N], x1, y1, x2, y2, c;

void insert(int X1, int Y1, int X2, int Y2, int C) {
    b[X1][Y1] += C;
    b[X1][Y2 + 1] -= C;
    b[X2 + 1][Y1] -= C;
    b[X2 + 1][Y2 + 1] += C;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }

    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
