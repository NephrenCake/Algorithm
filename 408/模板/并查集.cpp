#include <bits/stdc++.h>

using namespace std;

// ����x�����ڽڵ�
int find(int set[], int x) {
    if (set[x] != x)
        set[x] = find(set, set[x]);  // ·��ѹ��
    return set[x];
}

void UFSet(int n) {
    int p[n]; //�洢ÿ��������ڽڵ�

    // ��ʼ�����ٶ��ڵ�����1~n
    for (int i = 1; i <= n; i++)
        p[i] = i;

    // �ϲ�a��b���ڵ���������
    p[find(a)] = find(b);
};

int main() {

}
