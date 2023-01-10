#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, a[N], f[N], g[N];

int main() {
    while (cin >> a[n]) n++;  // δȷ��nʱ������

    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)  // �ϸ񵥵������ͷ��ϸ񵥵��½�����Եģ�����ǰ�������
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k++;
        g[k] = a[i];
        cnt = max(cnt, k + 1);
    }
    cout << cnt;
    return 0;
}
