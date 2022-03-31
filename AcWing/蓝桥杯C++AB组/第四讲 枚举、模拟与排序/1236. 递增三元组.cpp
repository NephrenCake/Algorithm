#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1212/

/**
 * ����������ѭ���� A < B < C O(3)
 * �Ż��������ݿ�֪ʱ�临�Ӷ�Ӧ�� <= nlog(n)��������ö��һ������
 *      �ʣ������ȹ̶� B���ٶ��� A��C
 *      �� A ���ж��ٸ�С�� B���� C ���ж��ٸ����� B��
 * ������
 *      1. ǰ׺��
 *      2. ����
 *      3. ˫ָ��
 */

/**
 * ��1 ����
 */

const int N = 1e5 + 10;

int n;
int A[N], B[N], C[N];
int num_a, num_c;
int l, r, m;

int find_num(int t) {
    // Ҫ���ǵ��޽���������һ������ȫ������һ������������
    // �ȶ���A
    l = -1, r = n - 1;
    while (l < r) {
        m = (l + r + 1) >> 1;
        if (A[m] < t) l = m;
        else r = m - 1;
    }
    num_a = r + 1;  // ע�����ҪС��t
    // �ٶ���C
    l = 0, r = n;
    while (l < r) {
        m = (l + r) >> 1;
        if (t < C[m]) r = m;
        else l = m + 1;
    }
    num_c = n - r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);
    for (int i = 0; i < n; i++) scanf("%d", &C[i]);
    sort(A, A + n);
    sort(B, B + n);
    sort(C, C + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        find_num(B[i]);
        ans += (long long) num_a * num_c;
    }
    cout << ans;
}

/**
 * ��2 ǰ׺��
 *      cnt[i] ��ʾ i ������� A �г��ֶ��ٴ�
 *      S[i] ��ʾ 0~i �� A ��һ�����ֶ��ٴ�
 *      ����ǰ׺�͵�ʱ�临�Ӷ�Ϊ 0(��ֵ��Χ)����������ֵ��Χ�����ݷ�Χ��ͬ�����Կ�����ǰ׺��
 */

/*
const int N = 1e5 + 10;

int n;
long long ans;  // ע����� �ᱬint
int A[N], B[N], C[N];
int As[N], Cs[N];  // as[i]��ʾ��A[]���ж��ٸ���С��b[i]
int cnt[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &A[i]), A[i]++;
    for (int i = 0; i < n; i++) scanf("%d", &B[i]), B[i]++;
    for (int i = 0; i < n; i++) scanf("%d", &C[i]), C[i]++;  // ע��ƫ��

    // ��A
    for (int i = 0; i < n; i++) cnt[A[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) As[i] = s[B[i] - 1];

    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);  // ���
    // ��C
    for (int i = 0; i < n; i++) cnt[C[i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) Cs[i] = s[N - 1] - s[B[i]];  // ע����� �Ǵ���b

    // �Ҵ�
    for (int i = 0; i < n; i++) ans += (long long)As[i] * Cs[i];  // ע����� �ᱬint
    cout << ans;
}
*/