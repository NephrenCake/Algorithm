#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/719/

const int N = 50;

int n;  // Êä³öÇ°nÏî
int f[N] = {0, 1, 1};

int dfs(int now) {
    if (f[now] != 0) {
        return f[now];
    }

    f[now] = dfs(now - 1) + dfs(now - 2);
    return f[now];
}

int main() {
    cin >> n;
    dfs(n);
    for (int i = 0; i < n; ++i) {
        cout << f[i] << " ";
    }
}