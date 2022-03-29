#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/94/

const int N = 25;

int n;
int ways[N];  // 状态数组 有效范围 1~n
bool used[N];  // 第二个状态标记是否已用

void dfs(int now) {
    if (now > n) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ways[i]);
        }
        printf("\n");
        return;  // 记得return
    }

    for (int i = 1; i <= n; ++i) {  // 从头看一遍是否都用过了
        if (!used[i]) {
            used[i] = true;
            ways[now] = i;
            dfs(now + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
}
