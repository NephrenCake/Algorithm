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

int n, d, k;  // N����־ ����ΪD��ʱ��� �յ�������K����
PII logs[N];
int cnt[N];
bool st[N];  // ��¼ÿ�������Ƿ�������

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
