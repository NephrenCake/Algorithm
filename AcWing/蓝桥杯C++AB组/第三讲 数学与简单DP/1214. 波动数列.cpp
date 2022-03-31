#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1216/

/**
 * ������https://www.acwing.com/solution/content/9223/��
 *      1. ���һ����Ϊ x����ڶ�����Ϊ x + d1����������Ϊ x + d1 + d2 �� ����� d1��d2 �� ��ʾ +a ���� -b��
 *      2. �����������Ϊ��x , x + d1, x + d1 + d2, x + d1 + d2 + d3, ��, x + d1 + d2 + �� + dn-1��
 *      3. ����Ϊ����֮��Ϊs������ת���ɣ�n * x + (n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + �� + dn-1 = s
 *      4. ����һ��ת����{s - [(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + �� + dn-1]} / n = x
 *      5. ��Ϊ x һ����������������ת���ɣ�s �� (n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + �� + dn-1 ģ n ��������ͬ��
 *      �������ת������������⣬����Ϳ���������dp�������ˡ�
 *      6. ״̬��ʾ��f[i][j]
 *              ���� ��ʾҪѡ i �� a ���� -b���ҳ� n ����Ϊ j �����м��ϵ�������
 *              Ŀ�� ��������f[n-1][s%n]��ֵ
 *              ���� count
 *      7. ״̬���㣺
 *              ���һ���� +a �����з��� | ���һ���� -b �����з���
 *              �� i ��ѡ a��(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + �� + 2 * dn-2 + a ģ n == j ģ n��
 *              ��(n - 1) * d1 + (n - 2) * d2 + (n - 3) * d3 + �� + 2 * dn-2 ģ n == j - a ģ n��
 *              ϵ�����±�֮��Ϊ n�����Ե� i ��ĵ�ϵ��Ϊ n - i��
 *              ���ԣ�f[i][j] = f[i - 1][j - (n - i) * a]
 *              ��i��ѡb��ͬ��f[i][j] = f[i - 1][j + (n - i) * b]
 * todo ֵ������
 */

const int N = 1010, MOD = 100000007;

int f[N][N];

int get_mod(int a, int b) {
    // �� a ���� b ��������
    return (a % b + b) % b;
}

int main() {
    int n, s, a, b;  // ����Ϊ n, ��Ϊ s, ���� a, ���߼��� b
    cin >> n >> s >> a >> b;

    f[0][0] = 1;  // ѡ 0 �� a �� -b��������Ϊ 0 �����м��ϵ������� 1 ����ͬ��ѡ 0 �� a �� -b����������Ϊ 0 �����м��ϵ������� 0 ����
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++) {
            // ����״̬�Ӽ���һ����ѡa��һ����ѡb��
            f[i][j] = (f[i - 1][get_mod(j - a * (n - i), n)] + f[i - 1][get_mod(j + b * (n - i), n)]) % MOD;
        }

    cout << f[n - 1][get_mod(s, n)];
}
