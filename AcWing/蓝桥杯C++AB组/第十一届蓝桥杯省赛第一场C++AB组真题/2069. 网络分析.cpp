#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/2071/

const int N = 10010;

int n, m;  // �ڵ������Ͳ�������
int arr[N];  // 1~n
int dat[N];  // 1~n

// ·��ѹ��
int find(int x) {
    if (arr[x] == x || arr[arr[x]] == arr[x])
        return arr[x];  // ����Լ��Ǹ��ڵ㣬���߸��ڵ�Ϊ���ڵ㣬��ֱ�ӷ��ظ��ڵ㡣
    int r = find(arr[x]);  // �ҵ�
    dat[x] += dat[arr[x]];
    arr[x] = r;
    return r;
}

void connect(int a, int b) {
    a = find(a);  // �ҵ�b���ھ������ĸ�
    b = find(b);  // �ҵ�a���ھ������ĸ�
    if (a == b)
        return;  // ͬһ������Ӱ��
    arr[b] = a;
    dat[b] -= dat[a];
}

void send(int p, int t) {
    p = find(p);  // �ҵ�p���ھ������ĸ�
    dat[p] += t;
}

int get_dat(int p) {
    if (find(p) == p)
        return dat[p];
    else
        return dat[p] + dat[find(p)];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) connect(b, c);
        else send(b, c);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", get_dat(i));
}
