#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/897/

/**
 * ״̬��ʾ f[i]
 *      ���� ������i��β���ϸ񵥵����������еļ���
 *      ���� max
 * ״̬����
 *      �ɡ�������i-1��β���ϸ񵥵����������еļ��ϡ�ת�Ƶ���������i��β���ϸ񵥵����������еļ��ϡ�
 *      ��βǰ��һ��������Ϊ 0 | 1 | ... | i - 1
 * ת�Ʒ���
 *      max(ans, f[i - 1] + 1)
 *
 */

const int N = 1010;

int n, res;
int f[N], a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = 1;  // �ض�����һ����
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])  // ֻ�е���i�������ڵ�j����ʱ�����ܰ������Ե�j������β���ϸ񵥵����������еļ��ϡ���״̬�����������ܵ���һ״̬���Ӽ���
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res;
}
