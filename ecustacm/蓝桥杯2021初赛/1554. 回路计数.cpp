#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;

const int N = 25;

vector<int> g[22];
int used[22], ans;

int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}

void dfs(int now, int cnt) {
    if (cnt == 22) {
        ans++;
        cout << ans;
        return;
    }
    used[now] = true;
    for (int& i : g[now]) {
        if (!used[i]) {
            dfs(i, cnt + 1);
            // cout << i << endl;
        }
    }
    used[now] = false;
}

int main() {
    for (int i = 1; i <= 21; i++)
        for (int j = i + 1; j <= 21; j++)
            if (gcd(i, j) == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
    dfs(1, 1);
    cout << ans;
}
