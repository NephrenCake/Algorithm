#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/797/

const int N = 100010;

int n, m;
int sum[N];
int l, r;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] = sum[i] + sum[i - 1];
    }
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
}
