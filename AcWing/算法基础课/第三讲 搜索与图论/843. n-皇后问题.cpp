#include <iostream>

using namespace std;

const int N = 20;
int n;
bool a[N][N], col[N], dg[N], udg[N];

void dfs(int idx) {
    if (idx == n + 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                if (a[i][j]) cout << "Q";
                else cout << ".";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        bool &x = col[i], &y = dg[i + n - idx], &z = udg[i + idx];
        if (!x && !y && !z) {
            x = y = z = true;
            a[idx][i] = true;
            dfs(idx + 1);
            a[idx][i] = false;
            x = y = z = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
}
