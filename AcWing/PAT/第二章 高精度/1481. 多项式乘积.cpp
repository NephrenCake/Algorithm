#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1483/

const int N = 1010;

int cnt;
double a[N], b[N], ans[N * 2];

void input(double lst[]) {
    int k;
    int t;
    double v;
    cin >> k;
    for (int i = 0 ; i < k; i++) {
        cin >> t >> v;
        lst[t] = v;
    }
}

int main() {
    input(a);
    input(b);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i] != 0 && b[j] != 0) {
                ans[i + j] += a[i] * b[j];
            }

    for (int i = 0; i < N * 2; i++)
        if (ans[i] != 0) cnt++;

    cout << cnt;
    for (int i = N * 2 - 1; i >= 0; i--)
        if (ans[i] != 0)
            printf(" %d %.1lf", i, ans[i]);
}
