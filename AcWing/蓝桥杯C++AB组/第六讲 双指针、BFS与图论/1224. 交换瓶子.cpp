#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1226/

/**
 * 置换群
 */

const int N = 10010;

int n;
int b[N];
bool st[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)  // 注意错误 范围是1~n
        cin >> b[i];

    int cnt = 0;
    // 注意 由于有判重数组，实际时间复杂度为 O(n)
    for (int i = 1; i <= n; i++)
        if (!st[i]) {
            cnt++;
            for (int j = i; !st[j]; j = b[j])
                st[j] = true;
        }
    cout << n - cnt;
}
