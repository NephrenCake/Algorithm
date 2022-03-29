#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1210/

/**
 * 初始状态到最终状态的最短路径，通常使用宽搜，但这里只是一个伪装成最优化问题的唯一确定问题
 * 时间复杂度 O(n)
 */

/**
 * 解1 c++ string 实现
 */

string a, b;
int ans;

void turn(int x) {
    if (a[x] == '*')
        a[x] = 'o';
    else
        a[x] = '*';
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            ans++;
            turn(i);
            turn(i + 1);
        }
    }
    cout << ans;
}

/**
 * 解2 c char[] 实现 练手
 */

/*
const int N = 110;

char a[N], b[N];
int n, ans;

void turn(int x) {
    if (a[x] == '*') a[x] = 'o';
    else a[x] = '*';
}

int main() {
    cin >> a >> b;
    n = strlen(a);

    for (int i = 0; i < n - 1;  i++) {
        if (a[i] != b[i]) {
            ans++;
            turn(i);
            turn(i + 1);
        }
    }

    cout << ans;
}
*/