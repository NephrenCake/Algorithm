#include <iostream>

using namespace std;

const int N = 1000010;
int n, a[N], b[N];
int q[N], len;

// 4. �����Ż���̰�ģ�
int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);  // cin ��ʱ
        a[t] = i;
    }
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        b[i] = a[t];
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        int l = 0, r = len, m, tar = b[i];
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

// #include <iostream>
//
// using namespace std;
//
// const int N = 1000010;
// int n, a[N], b[N], f[N], res;
//
// // 3. ���ݵ�һ�������е�����Ԫ�ؾ����ظ������������ַ���������������г��ȡ�ת��Ϊ���ڶ����ַ���������������г��ȡ�
// // Time Limit Exceeded
// int main() {
//     cin >> n;
//     for (int i = 1, t; i <= n; i++) {
//         cin >> t;
//         a[t] = i;  // ����ֵ���±ꡣ�����ߵĹ��������У��ض�����a[b[k]]�ϸ񵥵�����
//     }
//     for (int i = 1, t; i <= n; i++) {
//         cin >> t;
//         b[i] = a[t];
//     }
//
//     for (int i = 1; i <= n; i++) { // b��ǰi�����ֲ�����b[i]��β���������������
//         if (b[i] == 0) continue;  // ���Ϊ0���ʾ�����ڣ�����b[i]��β���������������Ҳ�Ͳ�����
//         f[i] = 1;
//         for (int j = 1; j < i; j++) {
//             if (b[j] < b[i])
//                 f[i] = max(f[i], f[j] + 1);
//             res = max(res, f[i]);
//         }
//     }
//     cout << res;
// }

// #include <iostream>
// #include <cstring>
//
// using namespace std;
//
// const int N = 1000010;
// int n, a[N], b[N], f[N], g[N];
//
// // 1. ��ά����������� Memory Limit Exceeded
// // 2. ���������Ż������������ Time Limit Exceeded
// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> b[i];
//
//     for (int i = 1; i <= n; i++) {
//         memcpy(g, f, sizeof f);
//         for (int j = 1; j <= n; j++) {
//             f[j] = max(g[j], f[j - 1]);
//             if (a[i] == b[j])
//                 f[j] = max(f[j], g[j - 1] + 1);
//         }
//     }
//     cout << f[n];
// }
