#include <iostream>

using namespace std;

const int N = 20;
int n, m, a[N], ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    // ö�ٶ�����״̬i��ÿһλ��ʾ��״̬�����Ƿ�ȡ�������
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;  // t����ǰ���������ĳ˻���cnt����ʲô��ǰѡ������������
        for (int j = 0; j < m; j++)   // ����ͳ��ÿ�������Ƿ�ѡ��
            if (i >> j & 1) {
                if ((long long) t * a[j] > n) {  // n�޷����ü��ϵĳ˻��������ü��ϸ���Ϊ0������
                    t = -1;
                    break;
                }
                t = t * a[j];
                cnt++;
            }
        if (t != -1) {
            if (cnt & 1) ans += n / t;
            else ans -= n / t;
        }
    }
    cout << ans;
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 20;
// int n, m, a[N], ans, cnt;
//
// // d ��������Ҫ�����ָ��� cur �����еĳ˻� idx ö�ٵ���λ��
// void dfs(int d, long long cur, int idx) {
//     if (d == 0) {
//         if (cnt & 1) ans += n / cur;
//         else ans -= n / cur;
//         return;
//     }
//     if (cur > n || idx > m) return;
//     dfs(d, cur, idx + 1);  // ��ѡ�����
//     dfs(d - 1, cur * a[idx], idx + 1);  // ѡ�������
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) cin >> a[i];
//     for (int i = 1; i <= m; i++)
//         cnt = i, dfs(i, 1, 1);
//     cout << ans;
// }
