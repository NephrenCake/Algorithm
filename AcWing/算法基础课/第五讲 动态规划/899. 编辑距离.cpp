#include <iostream>
#include <cstring>

using namespace std;

const int N =1010;
int n, m, lim, f[N][N];
string a[N], q;

int dp(string str1, string str2) {
    for (int i = 1; i < str1.size(); i++) f[i][0] = i;
    for (int j = 1; j < str2.size(); j++) f[0][j] = j;
    for (int i = 1; i < str1.size(); i++)
        for (int j = 1; j < str2.size(); j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (str1[i] != str2[j]));
        }
    return f[str1.size() - 1][str2.size() - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> q >> lim;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            int t = dp(" " + q, " " + a[j]);
            if (t <= lim)
                ans++;
        }
        cout << ans << endl;
    }
}
