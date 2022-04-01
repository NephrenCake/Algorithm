#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1243/

/**
 * 1. �ж���Щ���ж�������Щ��û����
 * 2. ����
 *      �ж����ĵ� score += 2 * ������
 *      �޶����ĵ� score--
 *      if (score > 5) st[id] = true;
 *      if (score <= 3) st[id] = false;
 *      for 1~n res++
 *    ʱ�临�Ӷ� N*T = 10^10 > 10^8
 * 3. �Ż�
 *      ˼�� ��������û�ж�����ʱ���Ƴٵ� ��һ�ζ���/���� ��ʱ����
 *      �ⷨ
 *          1. �����ж�����ʱ��������
 *              for ÿ������
 *                  ÿ�δ���һ������ id t cnt
 *                  score[id] -= t - last[id] - 1;
 *                  if (score[id] < 0) score[id] = 0;
 *                  if (score[id] <= 3) st[id] = false;
 *                  score[id] += cnt * 2;
 *                  if (score[id] > 5) st[id] = true;
 *          2. ���ݽṹ
 *              score[i] ��ʾ��i��������ȼ�
 *              last[i] ��ʾ��i������һ�ζ�����ʱ��
 *              st[i] ��ʾ��i�����Ƿ������Ȼ�����
 *          3. ����
 *              for ÿ������
 *                  if (last[id] < T)
 *                      score[id] -= T - last[id];
 *                      if (score[id] <= 3) st[id] = false;
 *              res = 0;
 *              for ÿ������
 *                  if st[id] res++
 */

#define x first
#define y second
#define PII pair<int, int>
const int N = 1e5 + 10;

int n, m, T;
int score[N], last[N];
bool st[N];
PII order[N];  // ʱ�䣬id

int main() {
    cin >> n >> m >> T;
    for (int i = 0; i < m; i++)
        scanf("%d%d", &order[i].x, &order[i].y);
    sort(order, order + m);  // �������Ȱ�ʱ�������ٰ�id����

    for (int i = 0; i < m;) {
        // ���ظ�����
        int j = i;
        while (j < m && order[j] == order[i]) j++;
        int t = order[i].x, id = order[i].y, cnt = j - i;  // ע����� ������cnt��¼j-i������i�Ѿ�����
        i = j;

        // �����ȥ�ۻ�
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
