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

// �� i �������� a ʱ�̷��䣬ָ����������Ϊ b����ʱΪ c ����������Ϊ d��
int cal(priority_queue<PII, vector<PII>, greater<>>* suspend, int a, int b, int c, int d) {
    // printf("a %d, b %d, c %d, d %d. \n", a, b, c, d);

    // ���µ�ǰ״̬
    while (!suspend[b].empty() && suspend[b].top().first <= a) {
        v[b] += suspend[b].top().second;
        suspend[b].pop();
    }
    // cout << v[b] << " " << d << " v[b] < d " << (v[b] < d) << endl;
    // ��ӵ�ǰ�¼�
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

    priority_queue<PII, vector<PII>, greater<>> suspend[N];  // [ռ�ñ��] <����ʱ�� �ͷ�����>
    while (m--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", cal(suspend, a, b, c, d));
    }
}