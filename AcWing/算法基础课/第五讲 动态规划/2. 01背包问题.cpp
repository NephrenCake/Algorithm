#include <iostream>

using namespace std;

const int N = 1010, M = 1010;
int n, m, v, w, f[M];

int main() {
    cin >> n >> m;
    // f[i][j] ��ǰi����Ʒ��ѡ�����������j��������ֵ
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = m; j; j--)
            if (j - v >= 0)
                f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m];
}
