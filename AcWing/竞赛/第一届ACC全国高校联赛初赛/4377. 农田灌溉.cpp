#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/description/4380/

void print(vector<bool> water) {
    for (auto && i : water) {
        if (i)
            cout << 'x';
        else
            cout << ' ';
    }
    cout << endl;
}

void sol(int n, int k, vector<bool> water, queue<pair<int, int>> q) {
    int time;  // 初始状态从1s之后开始
    // 广搜
    while (!q.empty()) {
        // print(water);
        int idx = q.front().first;
        int lv = q.front().second;
        q.pop();
        int nx = idx - 1;
        int ny = idx + 1;
        if (nx >= 0 && !water[nx]) {
            water[nx] = true;
            q.push(make_pair(nx, lv + 1));
        }
        if (ny < n && !water[ny]) {
            water[ny] = true;
            q.push(make_pair(ny, lv + 1));
        }
        time = lv;
    }
    cout << time << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n, k;  //  n 片连续的农田,    k  片农田中装有洒水器
        cin >> n >> k;
        vector<bool> water(n, false);
        queue<pair<int, int>> q;  // idx lv
        for (int j = 0; j < k; ++j) {
            int idx;
            cin >> idx;
            idx--;
            q.push(make_pair(idx, 1));
            water[idx] = true;
        }
        sol(n, k, water, q);
    }
}
