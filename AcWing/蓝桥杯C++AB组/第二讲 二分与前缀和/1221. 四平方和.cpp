#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// https://www.acwing.com/problem/content/1223/

/**
 * 1. ֻ��ö����������
 *      - ������Ҫ��4��δ֪��
 *      - ���ĸ�δ֪������ֱ���㣬������Ҫö��������
 * 2. �ÿռ任ʱ��
 *      - for c , c^2 <= N
 *            for d, c^2 + d^2 <= N  // ��c��ʼ����Ϊ˳���޹�
 *                save c^2 + d^2
 *      - for cs , cs^2 <= N
 *            for ds, cs^2 + ds^2 <= N
 *                t = n - cs^2 - ds^2
 *                if t in save
 */

/**
 * ��3 ��ϣ ���ۿ��У�ʵ�� unordered_map<int, PII> �����ˣ�ֻ�ܿ�����
 */

const int N = 1e8 + 10;
int cs[N];

int main() {
    int n;
    cin >> n;

    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++) {
            int t = d * d + c * c;
            if (cs[t] == 0) {
                cs[t] = c + 1;  // ��c��Ϊc+1�������п�
            }
        }

    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++) {
            int t = n - (b * b + a * a);
            if (cs[t] != 0) {
                int c = cs[t] - 1;
                int d = sqrt(t - c * c) + 1e-4;
                printf("%d %d %d %d", a, b, c, d);
                return 0;
            }
        }
}

/**
 * ��2 ����
 */

/*
const int N = 2500010;

struct Sum {
    int s, c, d;

    bool operator<(const Sum& t) const {
        if (s != t.s) return s < t.s;
        if (c != t.c) return c < t.c;
        else return d < t.d;
    }
} sum[N];

int main() {
    int n, m;
    cin >> n;

    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++)
            sum[m++] = {d * d + c * c, c, d};
    // cout << n << endl;  // ���d��0��ʼö�٣���n��ֵ�ᷢ���仯��ԭ������n, m ���ɾֲ������������� Segmentation Fault
    sort(sum, sum + m);

    for (int cs = 0; cs * cs <= n; cs++)
        for (int ds = cs; ds * ds + cs * cs <= n; ds++) {
            int t = n - (ds * ds + cs * cs);
            int l = 0, r = m - 1, mid;
            while (l < r) {
                mid = (r + l) >> 1;
                if (t <= sum[mid].s) r = mid;
                else l = mid + 1;
            }
            if (sum[r].s == t) {
                printf("%d %d %d %d", cs, ds, sum[r].c, sum[r].d);
                return 0;
            }
        }
}
*/

/**
 * ��1 ֱ�ӱ����������Ѿ���������
 */

/*
int main() {
    int n;
    cin >> n;

    for (int i = 0; i * i < n; i ++)
        for (int j = i; i * i + j * j < n; j++)
            for (int k = j; i * i + j * j + k * k < n; k++) {
                int l = n - (i * i + j * j + k * k);  // ע��Ҫ���� cmath
                int m = sqrt(l);
                if (m * m == l) {
                    printf("%d %d %d %d", i, j, k, m);
                    return 0;
                }
            }
}
*/