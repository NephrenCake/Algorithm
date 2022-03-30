#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1211/

/**
 * ��2 �Ż��㷨
 * n = a + b / c => c * n = c * a + b
 * 1. ö��a
 * 2. ö��b
 * 3. �ж�b�Ƿ����
 */

bool used[10], backup[10];
int n;  // �����������
int res = 0;

bool check(int c, int a) {
    long long  b = (long long) c * n - c * a;  // ��ֹ���
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
        if (!backup[i])  // ����ÿ��������һ����û�ù��ʹ���
            return false;

    return true;
}

void dfs_c(int now, int c, int a) {
    // ����ö�ٵ� now ������now��1~9������ǰ c ��ֵΪ c
    if (now > 9)
        return;  // ״̬����Ҷ�ڵ�

    if (check(c, a))  // ���ڶ�ÿ��aö�ٵ�ÿ��c�����ж��Ƿ����Ҫ��
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
    // ����ö�ٵ� now ������now��1~9������ǰ a ��ֵΪ a
    if (a > n) {
        return;  // ��֦1���ز�����==n
    } else {
        // ���a���������������ö��c��������now>9
        // ö��cʱ��nowֱ�Ӵӵ�ǰ��ʼ����Ϊ�ܹ�ֻ��ö��9����
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
 * ��1 ����
 * 1. ö��ȫ����
 * 2. ö��λ��  | a | b | c |
 * 3. �жϵ�ʽ�Ƿ����
 */

/*
int abc[10];  // ֵ��Χ 1~9
bool used[10];
int n;  // �����������
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

    if (a * c + b == c * n)  // ���벻����int��������ʧ����
        return true;
    else
        return false;
}

void dfs_abc(int now) {
    if (now > 9) {
        for (int l = 1; l <= 7; l++)
            for (int r = l + 1; r <= 8; r++)
                if (check(l, r))  // ö��λ���������˷ֽ��
                    res++;

        // for (int k = 1; k <= 9; k++) {
        //     printf("%d ", abc[k]);
        // }
        // printf("\n");
        return;
    }

    // ȫ����ö�� abc
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