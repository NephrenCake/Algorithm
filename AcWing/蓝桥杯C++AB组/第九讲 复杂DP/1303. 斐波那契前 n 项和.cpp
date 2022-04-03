#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/1305/

/**
 * todo 再做
 */

typedef long long LL;

const int N = 3;

int n, m;

void mul(int c[], int a[], int b[][N]) {//处理一维矩阵和方阵乘法
    int temp[N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i] = (temp[i] + (LL) a[j] * b[j][i]) % m;

    memcpy(c, temp, sizeof temp);  // sizeof 不能对传进来的参数使用，否则只是一个指针的长度
}

void mul(int c[][N], int a[][N], int b[][N]) {//处理方阵的乘法，利用了函数的重载
    int temp[N][N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (LL) a[i][k] * b[k][j]) % m;
    memcpy(c, temp, sizeof temp);
}

int main() {
    cin >> n >> m;

    int f1[3] = {1, 1, 1};
    int a[3][3] = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 0, 1},
    };

    n--;
    while (n) {
        if (n & 1)
            mul(f1, f1, a);
        mul(a, a, a);
        n >>= 1;
    }

    cout << f1[2];
}

/**
 * 暴力过不了
 */
/*
const int N = 4;

int n, m;
int fi[N];

int main() {
    cin >> n >> m;
    fi[2] = fi[1] = 1;
    int x, y, z, s;
    for (int i = 3; i <= n; i++) {
        x = i % N, y = (i - 1) % N, z = (i - 2) % N, s = (i - 3) % N;
        fi[x] = (fi[y] + fi[z]) % m;
        // printf("%d %d %d %d\n", x, y, z, fi[x]);
        fi[z] = (fi[z] + fi[s]) % m;
    }
    fi[y] = (fi[y] + fi[z]) % m;
    fi[x] = (fi[x] + fi[y]) % m;

    cout << fi[x];
}
*/