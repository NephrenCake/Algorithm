#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/2071/

const int N = 10010;

int n, m;  // 节点数量和操作数量
int arr[N];  // 1~n
int dat[N];  // 1~n

// 路径压缩
int find(int x) {
    if (arr[x] == x || arr[arr[x]] == arr[x])
        return arr[x];  // 如果自己是根节点，或者父节点为根节点，则直接返回根节点。
    int r = find(arr[x]);  // 找到
    dat[x] += dat[arr[x]];
    arr[x] = r;
    return r;
}

void connect(int a, int b) {
    a = find(a);  // 找到b所在局域网的根
    b = find(b);  // 找到a所在局域网的根
    if (a == b)
        return;  // 同一个树无影响
    arr[b] = a;
    dat[b] -= dat[a];
}

void send(int p, int t) {
    p = find(p);  // 找到p所在局域网的根
    dat[p] += t;
}

int get_dat(int p) {
    if (find(p) == p)
        return dat[p];
    else
        return dat[p] + dat[find(p)];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) connect(b, c);
        else send(b, c);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", get_dat(i));
}
