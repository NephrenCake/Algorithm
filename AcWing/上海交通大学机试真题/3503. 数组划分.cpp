#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], s[N], n, ans, dis = 0x3f3f3f3f, flag;

void dfs(int idx, int cur) {
    if (cur > s[n - 1] / 2) return;  // ֻѰ�ҽ�С������ͣ�����һ��һ���ܱ�ʾΪsum[n - 1] - cur
    if (s[n - 1] - 2 * cur < dis)
        ans = cur, dis = s[n - 1] - 2 * cur;
    if (dis == 0 || dis == 1)  // ����Ѿ��ҵ����������Ż��Ľ����ֱ�ӷ���
        flag = 1;
    if (flag) return;
    if (idx == -1) return;  // ����߽�ʱ���뷵�أ��ҵ����ʱҲ������ǰ���أ�����Ҫһ���ߵ��߽�

    dfs(idx - 1, cur + a[idx]);
    // ��������ȫѡʱ����ѡ�ϵ�����Ԫ��֮��Ϊcur + sum[idx - 1]�����ȫѡ����������ans���Ǿ�˵�����룬�ǾͲ��ñ�����
    if (s[idx - 1] + cur  >= ans)
        dfs(idx - 1, cur);
}

int main() {
    int t;
    while (cin >> t) a[n++] = t;

    sort(a, a + n);
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];

    dfs(n - 1, 0);
    cout << s[n - 1] - ans << " " << ans;
}
