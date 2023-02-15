#include <iostream>

using namespace std;

const int N = 1010;
int n, m, k;
string str[N], q;

bool dp(string a, string b, int k) {
    int f[N][N];
    for (int i = 1; i < a.size(); i++) f[i][0] = i;
    for (int j = 1; j < b.size(); j++) f[0][j] = j;
    for (int i = 1; i < a.size(); i++)
        for (int j = 1; j < b.size(); j++) {
            f[i][j] = f[i - 1][j - 1];
            if (a[i] != b[j]) {
                f[i][j] = min(f[i][j], f[i - 1][j]);
                f[i][j] = min(f[i][j], f[i][j - 1]);
                f[i][j]++;
            }
        }
    return f[a.size() - 1][b.size() - 1] <= k;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> str[i];

    while (m-- && cin >> q >> k) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dp(" " + str[i], " " + q, k);
        cout << ans << endl;
    }
}
