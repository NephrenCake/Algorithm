#include <iostream>

using namespace std;

const int N = 1010;
int n, a[N], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {  // ǰi��������a[i]Ϊ��β������������еĳ���
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        // cout << f[i] << " ";
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res;
}
