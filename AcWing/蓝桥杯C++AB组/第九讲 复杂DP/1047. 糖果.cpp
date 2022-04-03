#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1049/

/**
 * ״̬��ʾ f[i][j]
 *      ���� ���д�ǰ i ����Ʒ��ѡ�����ǹ��������� k ������Ϊ j �����з���
 *      ���� max
 * ״̬����
 *      ���д�ǰ i - 1 ����Ʒ��ѡ�����ǹ�����Ϊ j * k ��ѡ���ļ��ϣ���ѡ�� i ����Ʒ�� | ��ѡ�� i ����Ʒ��
 *      f[i][j] = max(f[i - 1][j] + f[i - 1][(j - w[i]) % k])
 */

const int N = 110;

int n, k;  // N ����Ʒ,������ K ��������
int w;
int f[N][N];

int main() {
    scanf("%d%d", &n, &k);
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w);
        for (int j = 0; j < k; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][(j + k - w % k) % k] + w);
    }
    printf("%d", f[n][0]);
}
