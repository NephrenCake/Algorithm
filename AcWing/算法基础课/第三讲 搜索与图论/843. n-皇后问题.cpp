#include <iostream>

using namespace std;

const int N = 10;
int n, a[N][N], ua[2 * N], ub[2 * N], uc[2 * N];

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if (a[i][j]) cout << "Q";
                else cout << ".";
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int y = 0; y < n; y++)
        if (!ua[n - x + y] && !ub[y] && !uc[x + y]) {
            ua[n - x + y] = ub[y] = uc[x + y] = 1;
            a[x][y] = 1;
            dfs(x + 1);
            a[x][y] = 0;
            ua[n - x + y] = ub[y] = uc[x + y] = 0;
        }
}

int main() {
    cin >> n;
    dfs(0);
}
