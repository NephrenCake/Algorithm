#include<iostream>

using namespace std;

const int N = 12010, M = 2010;

int n, m, v[N], w[N], f[M];

int main() {
    cin >> n >> m;
    int cnt = 0;  // ��n����Ʒ�����cnt���飬ÿ����һ��ѡ�񷽰�
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        for (int k = 1; k <= s; k *= 2) {  // �ֱ�����1��2��4������λһ��
            cnt++;  // ���������
            v[cnt] = a * k;  // �ô��������
            w[cnt] = b * k;  // �ô����ļ�ֵ
            s -= k;  // sҪ��С
        }
        if (s > 0) {  // ʣ���һ��
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    // ö�ٴ���n�ɸ���������������ر���תΪ01����
    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m];
}
