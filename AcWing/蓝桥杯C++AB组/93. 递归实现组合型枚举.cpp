#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/95/

const int N = 25;

int n, m;
int ways[N];  // 1~m

void dfs(int now) {
    if (n - (ways[now - 1] + 1) < m - now) {
        // 剪枝：如果 可以选择的个数 小于 需要再选择的个数，则提前退出。
        return;
    }

    if (now > m) {
        for (int i = 1; i <= m; i++) {
            printf("%d ", ways[i]);
        }
        printf("\n");
        return;
    }

    for (int i = ways[now - 1] + 1; i <= n; i++) {
        // 保证当前新插入的数比之前一个大
        // 可以不使用 used 数组，因为使用过的数必须是比当前数小
        ways[now] = i;
        dfs(now + 1);
    }
}

int main() {
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    dfs(1);
}