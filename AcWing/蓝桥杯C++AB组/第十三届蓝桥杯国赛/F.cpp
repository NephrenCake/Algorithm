#include <bits/stdc++.h>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getDays(int m_, int d_) {
    int a = 0;
    for (int i = 1; i < m_; i++)
        a += days[i];
    return a + d_;
}

const int N = 365 + 1;
int n, m, k, ans = -1e9;  // n张票，m最大费用，k最小距离
int checks[N];
bool used[N];

void dfs(int cur_day, int cur_cost) {
    if (cur_cost > m)
        return;
    ans = max(ans, cur_cost);

    // cout << cur_day << endl;

    for (int i = cur_day + k; i <= 365; i++)
        if (!used[i]) {
            used[i] = true;
            dfs(i, cur_cost + checks[i]);
            used[i] = false;
        }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i <= 365; i++)
        used[i] = true;
    for (int i = 1; i <= n; i++) {
        int m_, d_, v_;
        cin >> m_ >> d_ >> v_;
        checks[getDays(m_, d_)] = v_;
        used[getDays(m_, d_)] = false;
    }

    // for (int i = 1; i <= 365; i++)
    //     if (!used[i]) {
    //         cout << i << " " << checks[i] << endl;
    //     }

    for (int i = 1; i <= 365; i++)
        if (!used[i]) {
            used[i] = true;
            dfs(i, checks[i]);
            used[i] = false;
        }
    cout << ans;
    return 0;
}
/*
4 16 3
1 1 1
1 3 2
1 4 4
1 6 8

 */
