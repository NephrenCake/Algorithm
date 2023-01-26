#include <iostream>

using namespace std;

const int N = 100010;
int n, a[N];
int q[N], len;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {  // ǰi��������a[i]Ϊ��β������������еĳ���
        int l = 0, r = len, m, tar = a[i];
        while (l < r) {
            m = (l + r + 1) / 2;
            if (q[m] < tar) l = m;
            else r = m - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = tar;
    }

    cout << len;
}
