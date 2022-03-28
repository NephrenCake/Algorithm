#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/95/

const int N = 25;

int n, m;
int ways[N];  // 1~m

void dfs(int now) {
    if (n - (ways[now - 1] + 1) < m - now) {
        // ��֦����� ����ѡ��ĸ��� С�� ��Ҫ��ѡ��ĸ���������ǰ�˳���
        return;
    }

    if (now > m) {
        for (int i = 1; i <= m; i++) {
            printf("%d ", ways[i]);
        }
        printf("\n");
        return;
    }

    for (int i = ways[now - 1] + 1; i <= n; i++) {
        // ��֤��ǰ�²��������֮ǰһ����
        // ���Բ�ʹ�� used ���飬��Ϊʹ�ù����������Ǳȵ�ǰ��С
        ways[now] = i;
        dfs(now + 1);
    }
}

int main() {
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    dfs(1);
}