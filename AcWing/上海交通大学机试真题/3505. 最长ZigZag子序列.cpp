#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // f[i][0] ǰi����ĸ������i��β�ģ����һ��Ϊ�����ģ��z���г���
    for (int i = 1; i <= n; i++){
        f[i][0] = f[i][1] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) f[i][1] = max(f[i][1], f[j][0] + 1);
            else if (a[j] > a[i]) f[i][0] = max(f[i][0], f[j][1] + 1);
    }
    cout << max(f[n][0], f[n][1]);
}
