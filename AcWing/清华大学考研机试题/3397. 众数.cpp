#include <iostream>

using namespace std;

int mp[10][10], n, m;

int main() {
    cin >> n >> m;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        for (int j = 1; j <= m; j++) {
            mp[j][a % 10]++;
            a /= 10;
        }
    }
    for (int i = 1; i <= m; i++) {
        int ans = -1, cnt = -1;
        for (int j = 0; j <= 9; j++)
            if (mp[i][j] > cnt)
                ans = j, cnt = mp[i][j];
        cout << ans << endl;
    }
}
