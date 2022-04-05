#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/3494/

typedef pair<int, int> PII;
const int N = 200000 + 10;

int n, m, v[N];

// 第 i 个任务在 a 时刻分配，指定计算机编号为 b，耗时为 c 且算力消耗为 d。
int cal(priority_queue<PII, vector<PII>, greater<>>* suspend, int a, int b, int c, int d) {
    // printf("a %d, b %d, c %d, d %d. \n", a, b, c, d);

    // 更新当前状态
    while (!suspend[b].empty() && suspend[b].top().first <= a) {
        v[b] += suspend[b].top().second;
        suspend[b].pop();
    }
    // cout << v[b] << " " << d << " v[b] < d " << (v[b] < d) << endl;
    // 添加当前事件
    if (v[b] < d)
        return -1;
    v[b] -= d;
    suspend[b].push({a + c, d});
    return v[b];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);

    priority_queue<PII, vector<PII>, greater<>> suspend[N];  // [占用编号] <结束时间 释放算力>
    while (m--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", cal(suspend, a, b, c, d));
    }
}