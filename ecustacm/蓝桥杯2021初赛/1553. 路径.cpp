#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 2050, INF = 0x3f3f3f;

int n = 2021;      // �������
int dist[N];        // �洢���е㵽1�ŵ�ľ���
bool st[N];     // �洢ÿ�������̾����Ƿ���ȷ��
int g[N][N];  // �洢ÿ����

// ��1�ŵ㵽n�ŵ�����·������������򷵻�-1
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i ++ ){
        int t = -1;     // �ڻ�δȷ�����·�ĵ��У�Ѱ�Ҿ�����С�ĵ�
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // ��t����������ľ���
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int gcd(int a, int b) {  // ���Լ��
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (abs(i - j) <= 21) {
                int wi = i * j / gcd(i, j);
                g[i][j] = wi;
                g[j][i] = wi;
                // cout << wi << endl;
            }
        }
    }
    cout << dijkstra();
}
