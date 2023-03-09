#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = N << 1, INF = 0x3f3f3f3f;
int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], up[N];
int s1[N], s2[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int father) {
    // d1[u] = d2[u] = -INF;  //�������б�Ȩ�������ģ����Բ��ó�ʼ��Ϊ������
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs1(j, u);
        int d = d1[j] + w[i];
        if (d >= d1[u]) {
            d2[u] = d1[u], s2[u] = s1[u];
            d1[u] = d, s1[u] = j;
        } else if (d > d2[u])
            d2[u] = d, s2[u] = j;
    }
    // if (d1[u] == -INF) d1[u] = d2[u] = 0; //����Ҷ�ӽ��
}

void dfs2(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        if (s1[u] == j) up[j] = w[i] + max(up[u], d2[u]);   //son_u  = j�����ôδ����
        else up[j] = w[i] + max(up[u], d1[u]);              //son_u != j������������
        dfs2(j, u);
    }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    int res = INF;
    for (int i = 1; i <= n; i++) res = min(res, max(d1[i], up[i]));
    printf("%d\n", res);
}
