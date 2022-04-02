#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/1226/

/**
 * �û�Ⱥ
 */

const int N = 10010;

int n;
int b[N];
bool st[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)  // ע����� ��Χ��1~n
        cin >> b[i];

    int cnt = 0;
    // ע�� �������������飬ʵ��ʱ�临�Ӷ�Ϊ O(n)
    for (int i = 1; i <= n; i++)
        if (!st[i]) {
            cnt++;
            for (int j = i; !st[j]; j = b[j])
                st[j] = true;
        }
    cout << n - cnt;
}
