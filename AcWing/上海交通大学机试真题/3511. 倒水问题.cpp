#include <iostream>
#include <cstring>

using namespace std;

const int N = 4010;
int A, B, C, ans, x;
bool used[N], st[N][N];

void dfs(int a, int b, int c) {
    if (st[a][b]) return;
    st[a][b] = true;
    if (!used[c]) {
        used[c] = true;
        ans++;
    }

    x = min(a, B - b);  // a -> b
    dfs(a - x, b + x, c);
    x = min(a, C - c);  // a -> c
    dfs(a - x, b, c + x);
    x = min(A - a, b);  // b -> a
    dfs(a + x, b - x, c);
    x = min(C - c, b);  // b -> c
    dfs(a, b - x, c + x);
    x = min(A - a, c);  // c -> a
    dfs(a + x, b, c - x);
    x = min(B - b, c);  // c -> b
    dfs(a, b + x, c - x);
}

int main() {
    while (cin >> A >> B >> C) {
        ans = 0;
        memset(used, false, sizeof used);
        memset(st, false, sizeof st);
        dfs(0, 0, C);
        cout << ans;
    }
}
