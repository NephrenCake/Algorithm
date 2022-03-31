#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1247/

int n, t;
long long ans;

// 0 1 2 9
bool is_ok(int i, int j, int k, int l, int m) {
    return (i == 0 && (j + k + l + m != 0) || i == 1 || i == 2 || i == 9) ||
           (j == 0 && (k + l + m != 0) || j == 1 || j == 2 || j == 9) ||
           (k == 0 && (l + m != 0) || k == 1 || k == 2 || k == 9) ||
           (l == 0 && (m != 0) || l == 1 || l == 2 || l == 9) ||
           (m == 1);
}

int main() {
    cin >> n;

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    for (int m = 0; m <= 1; m++)
                        if (is_ok(i, j, k, l, m)) {
                            t = m * 10000 + l * 1000 + k * 100 + j * 10 + i;
                            if (t <= n)
                                ans += t;
                        }

    cout << ans;
}

/*
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;

    for (int i = 1; i <= n; i ++ ) {
        int x = i;
        while(x) {
            int t = x % 10;  // 取出x的个位数
            x /= 10;         // 取它的上一位
            if (t == 0 || t == 2 || t == 1 || t == 9) {
                res += i;
                break;
            }
        }
    }

    cout << res << endl;
}
*/