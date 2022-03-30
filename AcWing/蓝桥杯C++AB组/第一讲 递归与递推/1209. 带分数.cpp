#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1211/

/**
 * 解2 优化算法
 * n = a + b / c => c * n = c * a + b
 * 1. 枚举a
 * 2. 枚举b
 * 3. 判断b是否成立
 */

bool used[10], backup[10];
int n;  // 输入的正整数
int res = 0;

bool check(int c, int a) {
    long long  b = (long long) c * n - c * a;  // 防止溢出
    if (a == 0 || b == 0 || c == 0)
        return false;

    memcpy(backup, used, sizeof used);
    while (b > 0) {
        int x = b % 10;
        b /= 10;

        if (x != 0 && !backup[x]) {
            backup[x] = true;
        } else {
            return false;
        }
    }
    for (int i = 1; i <= 9; i++)
        if (!backup[i])  // 遍历每个数，有一个还没用过就错误
            return false;

    return true;
}

void dfs_c(int now, int c, int a) {
    // 正在枚举第 now 个数（now：1~9），当前 c 的值为 c
    if (now > 9)
        return;  // 状态树的叶节点

    if (check(c, a))  // 对于对每个a枚举的每个c，都判断是否符合要求
        res++;
    // printf("%d \n", c);

    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs_c(now + 1, c * 10 + i, a);
            used[i] = false;
        }
    }
}

void dfs_a(int now, int a) {
    // 正在枚举第 now 个数（now：1~9），当前 a 的值为 a
    if (a > n) {
        return;  // 剪枝1：必不可能==n
    } else {
        // 如果a满足情况，则立即枚举c。而不是now>9
        // 枚举c时，now直接从当前开始，因为总共只会枚举9个数
        dfs_c(now + 1, 0, a);
        // printf("%d \n", a);
    }

    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs_a(now + 1, a * 10 + i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs_a(1, 0);
    cout << res;
}

/**
 * 解1 暴力
 * 1. 枚举全排列
 * 2. 枚举位数  | a | b | c |
 * 3. 判断等式是否成立
 */

/*
int abc[10];  // 值范围 1~9
bool used[10];
int n;  // 输入的正整数
int res = 0;

void get_abc(int& a, int& b, int& c, int l, int r) {
    int p = 1;
    while (p <= l)
        a = a * 10 + abc[p++];
    while (p <= r)
        b = b * 10 + abc[p++];
    while (p <= 9)
        c = c * 10 + abc[p++];
}

bool check(int l, int r) {
    int a = 0, b = 0, c = 0;
    get_abc(a, b, c, l, r);
    // printf("%d %d %d \n", a, b, c);

    if (a * c + b == c * n)  // 必须不能用int除法，损失精度
        return true;
    else
        return false;
}

void dfs_abc(int now) {
    if (now > 9) {
        for (int l = 1; l <= 7; l++)
            for (int r = l + 1; r <= 8; r++)
                if (check(l, r))  // 枚举位数，代表了分界点
                    res++;

        // for (int k = 1; k <= 9; k++) {
        //     printf("%d ", abc[k]);
        // }
        // printf("\n");
        return;
    }

    // 全排列枚举 abc
    for (int l = 1; l <= 9; l++) {
        if (!used[l]) {
            used[l] = true;
            abc[now] = l;
            dfs_abc(now + 1);
            used[l] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs_abc(1);
    printf("%d ", res);
}
*/