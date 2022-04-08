#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3422/

#define x first
#define y second
typedef pair<int, int> PII;

const int N = 100010;

int n, m;
PII stk[N];
int ans[N];

int main() {
    cin >> n >> m;
    int top = 0;
    while (m--) {
        int p, q;
        cin >> p >> q;
        if (p == 0) {  // 将 1~i 降序排列
            while (top && stk[top].x == 0) q = max(q, stk[top--].y);
            while (top >= 2 && stk[top - 1].y <= q) top -= 2;
            stk[++top] = {0, q};
        } else if (top) {  // 将 i~n 升序排列。
            while (top && stk[top].x == 1) q = min(q, stk[top--].y);
            while (top >= 2 && stk[top - 1].y >= q) top -= 2;
            stk[++top] = {1, q};
        }
    }
    int k = n, l = 1, r = n;
    for (int i = 1; i <= top && l <= r; i++) {
        if (stk[i].x == 0)
            while (r > stk[i].y && l <= r) ans[r--] = k--;
        else
            while (l < stk[i].y && l <= r) ans[l++] = k--;
    }
    if (top % 2)
        while (l <= r) ans[l++] = k--;
    else
        while (l <= r) ans[r--] = k--;

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}
