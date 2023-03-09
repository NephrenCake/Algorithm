#include <iostream>

using namespace std;

const int N = 35;
int n, a[N], f[N][N], path[N], cnt;

void dfs(int l, int r) {
    if (l == r) {
        path[cnt++] = r;
        return;
    }
    if (a[l] + f[l + 1][r] == f[l][r]) {
        path[cnt++] = l;
        dfs(l + 1, r);
    } else if (a[r] + f[l][r - 1] == f[l][r]) {
        path[cnt++] = r;
        dfs(l, r - 1);
    } else {
        int k = l + 1;
        while (f[l][k - 1] * f[k + 1][r] + a[k] != f[l][r]) k++;
        path[cnt++] = k;
        dfs(l, k - 1);
        dfs(k + 1, r);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i][i] = a[i];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                if (k == i) f[i][j] = max(f[i][j], a[k] + f[k + 1][j]);
                else if (k == j) f[i][j] = max(f[i][j], a[k] + f[i][k - 1]);
                else f[i][j] = max(f[i][j], f[i][k - 1] * f[k + 1][j] + a[k]);
        }
    cout << f[1][n] << endl;
    dfs(1, n);
    for (int i = 0; i < cnt; i++) cout << path[i] << " ";
}
