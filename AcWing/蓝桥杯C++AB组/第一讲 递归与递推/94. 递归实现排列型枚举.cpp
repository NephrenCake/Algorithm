#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/94/

const int N = 25;

int n;
int ways[N];  // ״̬���� ��Ч��Χ 1~n
bool used[N];  // �ڶ���״̬����Ƿ�����

void dfs(int now) {
    if (now > n) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ways[i]);
        }
        printf("\n");
        return;  // �ǵ�return
    }

    for (int i = 1; i <= n; ++i) {  // ��ͷ��һ���Ƿ��ù���
        if (!used[i]) {
            used[i] = true;
            ways[now] = i;
            dfs(now + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
}
