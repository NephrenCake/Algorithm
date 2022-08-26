#include <bits/stdc++.h>

using namespace std;

// 返回x的祖宗节点
int find(int set[], int x) {
    if (set[x] != x)
        set[x] = find(set, set[x]);  // 路径压缩
    return set[x];
}

void UFSet(int n) {
    int p[n]; //存储每个点的祖宗节点

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i++)
        p[i] = i;

    // 合并a和b所在的两个集合
    p[find(a)] = find(b);
};

int main() {

}
