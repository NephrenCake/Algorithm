#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/284/

const int N = 310;
int n;
int s[N];
int f[N][N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i], s[i] += s[i - 1];
    }

    for (int len = 2; len <= n; ++len) {
        // 1. ��������һ����ö�ٳ��ȡ����䶨��һ������ұգ����� i��j �����˵�
        // j = i + len - 1;
        // ��ˣ�len >= 2������ 2 ���ٰ��� i��j �����㣬j ���� i �غ�
        for (int i = 1; i + len - 1 <= n; ++i) {
            // 2. ��ö���������
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; ++k) {
                // ע�⣬f[i][j] һֱ��ά��һ����Сֵ
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    // ѭ����״̬��ʾ����ʽ��һ����ͬ��������Ҫ��ѭ���ϵĶ���
    cout << f[1][n];
}
