#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/1228/

/**
 * ״̬��ʾ f[i][j]
 *      ���� ǰ i �����ܺ��� j
 *      ���� �����Ƿ�ǿ�
 * ״̬����
 *      ���õ� i ������ | �� i �������� 1 �� | ���� | �� i �������� k ��
 */

/**
 * ��1 ����
 */
const int N = 10010;

int n;
bool f[110][N];
int a[110];

int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}

int main() {
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d = gcd(d, a[i]);
    }

    if (d != 1) cout << "INF";
    else {
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < N; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= a[i])
                    f[i][j] |= f[i][j - a[i]];
            }
        int res = 0;
        for (int i = 0; i < N; i++)
            if (!f[n][i])
                res++;
        cout << res;
    }
}

/**
 * ��2 �Ż��ռ�
 */
/*
const int N = 10010;

int n;
bool f[N];
int arr[110];

int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}

int main() {
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        d = gcd(d, arr[i]);
    }

    if (d != 1) cout << "INF";
    else {
        f[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < N; j++)
                if (j >= arr[i])
                    f[j] |= f[j - arr[i]];
        int res = 0;
        for (int i = 0; i < N; i++)
            if (!f[i])
                res++;
        cout << res;
    }
}
*/