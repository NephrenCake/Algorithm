#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, P = 22, Q = 80;
int n, V1, V2, v1[N], v2[N], w[N], f[N][P][Q];

// ���ط�
int main() {
    cin >> V1 >> V2 >> n;  // ������,���׵ĸ���
    for (int i = 1; i <= n; i++)
        cin >> v1[i] >> v2[i] >> w[i];  // ���͵�����������������

    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;  // ״̬��ʾ��ǰ0����Ʒ������1��С��0������2��С��0������ܼ�ֵ

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= V1; j++)
            for (int k = 0; k <= V2; k++) {
                f[i][j][k] = f[i - 1][j][k];  // ��ѡ��i����Ʒ
                // ѡ��i����Ʒ��f[0][0][0]��ʾ�����з���Ϊ��������ļ��ϡ��������ߵ���������������Ǹ���ʱ������������0��״̬�ȼ�
                // �磬f[1][1][1]���Դ�f[0][-1][-1]����f[0][0][0]��ת�ƹ�����f[0][-1][-1]��f[0][0][0]����0
                f[i][j][k] = min(f[i][j][k], f[i - 1][max(j - v1[i], 0)][max(k - v2[i], 0)] + w[i]);
            }
    cout << f[n][V1][V2];
}
