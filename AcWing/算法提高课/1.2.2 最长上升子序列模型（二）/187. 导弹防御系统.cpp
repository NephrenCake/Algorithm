#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;
int n, a[N], ans, up[N], down[N];

void dfs(int su, int sd, int i) {
    if (su + sd >= ans) return;
    if (i == n) {
        // ans = min(ans, su + sd);
        ans = su + sd;// 能下来已经说明su + sd < ans
        return;
    }

    // 递增
    int k = 0, t;
    while (k < su && up[k] >= a[i]) k++;
    t = up[k];
    up[k] = a[i];
    if (k >= su) dfs(su + 1, sd, i + 1);
    else dfs(su, sd, i + 1);
    up[k] = t;
    // 递减
    k = 0;
    while (k < sd && down[k] <= a[i]) k++;
    t = down[k];
    down[k] = a[i];
    if (k >= sd) dfs(su, sd + 1, i + 1);
    else dfs(su, sd, i + 1);
    down[k] = t;
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        ans = n;

        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;
int n, a[N], ans, up[N], down[N];

void dfs(int su, int sd, int i, bool inc) {
    if (su + sd >= ans) return;
    if (i == n) {
        ans = su + sd;
        return;
    }

    if (inc) {  // 单增
        int k = 0;
        while (k < su && up[k] >= a[i]) k++;
        int t = up[k];  // ！！！注意保存上下文，要紧贴修改的语句，否则可能保存错误
        up[k] = a[i];
        su = max(su, k + 1);
        dfs(su, sd, i + 1, true);
        dfs(su, sd, i + 1, false);
        up[k] = t;
    } else {
        int k = 0;
        while (k < sd && down[k] <= a[i]) k++;
        int t = down[k];
        down[k] = a[i];
        sd = max(sd, k + 1);
        dfs(su, sd, i + 1, true);
        dfs(su, sd, i + 1, false);
        down[k] = t;
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        ans = n;

        dfs(0, 0, 0, true);
        dfs(0, 0, 0, false);
        cout << ans << endl;
    }
}

 */
