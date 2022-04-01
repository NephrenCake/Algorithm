#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1243/

/**
 * 1. 判断哪些店有订单，哪些店没订单
 * 2. 暴力
 *      有订单的店 score += 2 * 订单数
 *      无订单的店 score--
 *      if (score > 5) st[id] = true;
 *      if (score <= 3) st[id] = false;
 *      for 1~n res++
 *    时间复杂度 N*T = 10^10 > 10^8
 * 3. 优化
 *      思想 将连续的没有订单的时间推迟到 下一次订单/结束 的时候处理
 *      解法
 *          1. 将所有订单按时间序排序
 *              for 每个订单
 *                  每次处理一批订单 id t cnt
 *                  score[id] -= t - last[id] - 1;
 *                  if (score[id] < 0) score[id] = 0;
 *                  if (score[id] <= 3) st[id] = false;
 *                  score[id] += cnt * 2;
 *                  if (score[id] > 5) st[id] = true;
 *          2. 数据结构
 *              score[i] 表示第i个店的优先级
 *              last[i] 表示第i个店上一次订单的时间
 *              st[i] 表示第i个店是否处于优先缓存中
 *          3. 结束
 *              for 每个订单
 *                  if (last[id] < T)
 *                      score[id] -= T - last[id];
 *                      if (score[id] <= 3) st[id] = false;
 *              res = 0;
 *              for 每个订单
 *                  if st[id] res++
 */

#define x first
#define y second
#define PII pair<int, int>
const int N = 1e5 + 10;

int n, m, T;
int score[N], last[N];
bool st[N];
PII order[N];  // 时间，id

int main() {
    cin >> n >> m >> T;
    for (int i = 0; i < m; i++)
        scanf("%d%d", &order[i].x, &order[i].y);
    sort(order, order + m);  // 将订单先按时间排序，再按id排序

    for (int i = 0; i < m;) {
        // 找重复订单
        int j = i;
        while (j < m && order[j] == order[i]) j++;
        int t = order[i].x, id = order[i].y, cnt = j - i;  // 注意错误 必须用cnt记录j-i，后面i已经更新
        i = j;

        // 处理过去累积
        score[id] -= t - last[id] - 1;
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = false;

        score[id] += cnt * 2;
        if (score[id] > 5) st[id] = true;

        last[id] = t;
    }

    for (int i = 1; i <= n; i++)
        if (last[i] < T) {
            score[i] -= T - last[i];
            if (score[i] <= 3) st[i] = false;
        }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += st[i];
    printf("%d\n", ans);
}
