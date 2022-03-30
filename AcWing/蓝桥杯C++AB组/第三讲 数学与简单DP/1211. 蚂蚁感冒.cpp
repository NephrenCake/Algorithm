#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1213/

/**
 * ���ʣ�
 * 1. ��ͷ�ȼ��ڴ�������껥��
 * ��һ�����������ߵ����:
 * 1. �ұ������ߵģ���Ȼ����Ⱦ
 * 2. �ұ������ߣ���Ȼ���ᱻ��Ⱦ
 * 3. ��������ߣ���Ȼ���ᱻ��Ⱦ
 * 4. ���������:
 *      (1)�ұߴ��������ߣ����Ȼ����Ⱦ
 *      (2)�ұ߲����������ߣ����Ȼ���ᱻ��Ⱦ
 */

const int N = 55;

int n;
int x[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int l2r = 0, r2l = 0;  // �ֱ��ʾ��������ߵ��������������ұ������ߵ���������
    for (int i = 0; i < n; i++)
        if (abs(x[i]) < abs(x[0]) && x[i] > 0)
            l2r++;
        else if (abs(x[i]) > abs(x[0]) && x[i] < 0)
            r2l++;

    if (x[0] > 0 && r2l == 0 || x[0] < 0 && l2r == 0)
        cout << 1 << endl;
    else
        cout << l2r + r2l + 1 << endl;
}
