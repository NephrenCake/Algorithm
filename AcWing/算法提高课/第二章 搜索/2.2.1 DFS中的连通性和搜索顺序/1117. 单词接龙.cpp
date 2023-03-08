#include <iostream>

using namespace std;

const int N = 25;
int n, used[N], ans;
string words[N];
char start;

int getd(string a, string b) {
    for (int i = 1; i < min(a.size(), b.size()); i++)
        if (a.substr(a.size() - i, i) == b.substr(0, i))
            return i;
}

void dfs(int cnt, string cur) {
    ans = max(ans, (int) cur.size());
    if (cnt == 2 * n) return;
    for (int i = 0; i < n; i++)
        if (used[i] != 2) {
            int d = getd(cur, words[i]);
            if (d) {
                used[i]++;
                dfs(cnt + 1, cur.substr(0, cur.size() - d) + words[i]);
                used[i]--;
            }
        }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> words[i];
    cin >> start;

    for (int i = 0; i < n; i++)
        if (words[i][0] == start) {
            used[i]++;
            dfs(1, words[i]);
            used[i]--;
        }
    cout << ans;
}
