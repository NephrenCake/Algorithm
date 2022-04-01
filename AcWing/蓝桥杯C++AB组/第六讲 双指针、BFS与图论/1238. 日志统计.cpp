#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1240/

#define x first
#define y second
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, d, k;  // N行日志 长度为D的时间段 收到不少于K个赞
PII logs[N];
int cnt[N];
bool st[N];  // 记录每个帖子是否是热帖

int main() {
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &logs[i].x, &logs[i].y);

    sort(logs, logs + n);

    for (int i = 0, j = 0; i < n; i++) {
        int id = logs[i].y;
        cnt[id]++;
        while (logs[i].x - logs[j].x >= d) {
            cnt[logs[j].y]--;
            j++;
        }

        if (cnt[id] >= k) st[id] = true;
    }

    for (int i = 0; i <= 1e5; i++)
        if (st[i])
            printf("%d\n", i);
}
