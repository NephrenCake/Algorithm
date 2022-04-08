#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3421/

typedef long long LL;

int n;

LL C(int a, int b) {
    // C(a, b) = a!/b!(a-b)!
    LL res = 1;
    for (int i = a, j = 1; j <= b; i--, j++) {
        res = res * i / j;
        if (res > n) return res;  // ����n�������壬�ҷ�ֹ��LL
    }
    return res;
}

bool check(int k) {
    int l = 2 * k, r = max(n, l);
    while (l < r) {
        int m = (l + r) >> 1;
        if (n <= C(m, k)) r = m;  // �ҵ�һ�����ڵ���tar����
        else l = m + 1;
    }
    if (C(r, k) != n) return false;

    cout << 1ll * (r + 1) * r / 2 + k + 1 << endl;
    return true;
}

int main() {
    cin >> n;
    // ��������ö��16��б�У����ز�©�����н�
    // k����ڼ�б�У�Ҳ�������ֵ�����е�λ����0��ʼ������
    for (int k = 16;; k--)
        if (check(k)) break;
}
