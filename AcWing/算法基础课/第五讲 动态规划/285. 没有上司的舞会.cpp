#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;
int n, happy[N], f[N][2];
int e[N], ne[N], h[N], idx;
bool has_father[N];

void add(int a, int b) {  // 把a插入树中
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    for (int i = h[u]; i != -1; i = ne[i]) {  // 遍历树
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][1], f[j][0]);
        f[u][1] += f[j][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];

    memset(h, -1, sizeof h);
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;  // b是a的上司
        has_father[a] = true;
        add(b, a);
    }

    int root = 1;
    while (has_father[root]) root++; //找根节点
    dfs(root);
    cout << max(f[root][0], f[root][1]);
}
