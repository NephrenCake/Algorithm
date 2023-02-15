#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m, all[3 * N], a[3 * N], cnt, x[N], c[N], l[N], r[N];  // all�������±�->ԭ�����±� a������ǰ׺��

int find(int tar) {
    int l = -1, r = cnt, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (all[m] < tar) l = m;
        else r = m - 1;
    }
    return r + 1;  // �ҵ���һ�����ڵ���x��λ��
}

int main()  {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i] >> c[i], all[++cnt] = x[i];  // 1. ��¼������Ϣ�����г��ֹ��ĵ�
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i], all[++cnt] = l[i], all[++cnt] = r[i];
    sort(all + 1, all + 1 + cnt);  // 2. �洢�±��1��ʼ����ΪҪǰ׺��
    for (int i = 0; i < n; i++) a[find(x[i])] += c[i];  // 3. ����ɢ�������д洢ֵ
    for (int i = 1; i <= cnt; i++) a[i] += a[i - 1];  // 4. ����ǰ׺��
    for (int i = 0; i < m; i++) cout << a[find(r[i])] - a[find(l[i]) - 1] << endl;
}
