#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1242/

const int N = 1e5 + 10;

int n, ans = 1;
long long max_;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int d = 1, i = 1; i <= n; d++, i *= 2) {
        long long s = 0;
        for (int j = i; j < i + (1 << (d - 1)) && j <= n; j++)
            // ע��1 j ����Խ��
            // ע��2 2�ļ��η�������λ����
            s += a[j];
        if (max_ < s) {
            max_ = s;
            ans = d;
        }
    }
    cout << ans;
}
