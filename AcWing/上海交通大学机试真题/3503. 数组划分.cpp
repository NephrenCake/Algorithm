#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, a[N], sum[N];
int dis = 0x3f3f3f3f, ans;  // ������͵ľ��� ��С���Ǹ������
bool flag;

void dfs(int cur, int idx) {
    if (flag) return;
    if (cur > sum[n - 1] / 2) return;  // ֻѰ�ҽ�С������ͣ�����һ��һ���ܱ�ʾΪsum[n - 1] - cur
    if (idx == -1) {
        int d = sum[n - 1] - 2 * cur;
        if (d < dis) {
            dis = d;
            ans = cur;
            if (dis == 0 || dis == 1)  // ����Ѿ��ҵ����������Ż��Ľ����ֱ�ӷ���
                flag = true;
        }
        return;
    }

    dfs(cur + a[idx], idx - 1);
    // ��������ȫѡʱ����ѡ�ϵ�����Ԫ��֮��Ϊcur + sum[idx - 1]�����ȫѡ������disԽ��Խ���ǾͲ��ñ�����
    int next_max = cur + sum[idx - 1];
    if (!(next_max < sum[n - 1] / 2 && sum[n - 1] - 2 * (next_max) > dis))
        dfs(cur, idx - 1);
    // else
    //     cout << "next_max " << next_max << " " << sum[n - 1] / 2 << endl;
}

int main() {
    int t;
    while (cin >> t) a[n++] = t;

    sort(a, a + n);  // ��С����������Խ�ʱ���515ms����17ms
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = a[i] + sum[i - 1];  // ǰ׺��

    dfs(0, n - 1);  // �Ӻ���ǰ����ÿ��Ԫ�أ�����ʹ��ǰ׺��Ԥ�м�֦
    cout << sum[n - 1] - ans << " " << ans;
}
