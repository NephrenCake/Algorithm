#include<iostream>
#include<cmath>

using namespace std;

const int N = 24;
int n, m, v[N], s[N], res = 1e9, R[N], H[N];  //��¼ÿ��İ뾶�͸ߣ���Ϊ���õ���һ��ĸ߶�

void dfs(int idx, int cv, int cs) {  // idx��ǰ��Σ�cv��ǰ���������ͣ�cs��ǰ����������
    if (cv + v[idx] > n) return;
    if (cs + s[idx] >= res) return;
    if (cs + 2 * (n - cv) / R[idx + 1] >= res) return;  // ע�⹫ʽ�Ƶ�
    if (idx == 0) {
        if (cv == n) res = cs;
        return;
    }
    //����˳����R��H���Ӵ�С
    for (int r = min(R[idx + 1] - 1, (int) sqrt((n - cv - v[idx - 1]) / idx)); r >= idx; r--)
        for (int h = min(H[idx + 1] - 1, (n - cv - v[idx - 1]) / r / r); h >= idx; h--) {
            H[idx] = h, R[idx] = r;
            //��ײ��ʱ����Ҫ����r*r
            int t = idx == m ? r * r : 0;
            dfs(idx - 1, cv + r * r * h, cs + 2 * r * h + t);
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        v[i] += + i * i * i, s[i] += + 2 * i * i;
    //m+1�㲻���ڣ���Ϊ�ڱ������ٱ߽�������ж�
    R[m + 1] = H[m + 1] = 1e9;
    dfs(m, 0, 0);
    if (res == 1e9) res = 0;
    cout << res;
}
