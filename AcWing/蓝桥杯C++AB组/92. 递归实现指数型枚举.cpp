#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/94/

const int N = 25;

int n;
bool st[N];

void dfs(int now) {
    if (now > n) {
        for (int i = 1; i <= n; i++)
            if (st[i])
                printf("%d ", i);
        printf("\n");
        return;
    }

    st[now] = true;
    dfs(now + 1);
    st[now] = false;
    dfs(now + 1);
}

int main() {
    cin >> n;
    dfs(1);
}
