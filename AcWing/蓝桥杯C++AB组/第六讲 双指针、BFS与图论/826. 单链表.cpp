#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/828/

const int N = 100010;

int n;
int h[N], e[N], ne[N], head, idx;

// ��������г�ʼ��
void init() {
    head = -1;  // �൱�ڱ����ڵ㣬������ ne[N] ��ͬ��ָ�� -1 ʱ����ʾ������û������
    idx = 0;  // ָ����һ��������Ŀռ��±꣬ͬʱ��ʾ�Ѿ������˼���Ԫ�أ�������ɾ����
}

// �� x ���뵽ͷ�ڵ���
void insert_to_head(int x) {
    e[idx] = x;  // ���ڴ�����Ŀռ��б���ֵ
    ne[idx] = head;  // ָ���½ڵ�� next ��
    head = idx;  //  head �����ڵ�����ָ���һ��Ԫ��
    idx++;  // ������ռ�ָ��������һλ��Ϊ��һ�β���Ԫ����׼����
}

// �� x ���뵽�±�Ϊ k-1 �ĵ�ĺ���
void add(int k, int x) {
    e[idx] = x;  // ���ڴ�����Ŀռ��б���ֵ
    ne[idx] = ne[k - 1];  // ָ���½ڵ㣨[idx]���� next ��Ϊ�ڵ㣨[k - 1]���� next ��
    ne[k - 1] = idx;  // ����ǰһ������ k ������ģ��ڵ�� next ��Ϊ�½ڵ�
    idx++;  // ������ռ�ָ��������һλ
}

// ���±��� k-1���� k �����룩�ĵ����ĵ��ɾ��
void remove(int k) {
    if (k == 0)
        head = ne[head];  // ɾ��ͷ�ڵ�
    else
        ne[k - 1] = ne[ne[k - 1]];//��k��ָ��ָ��k��һ���˵���һ���ˣ����м����λ�ͱ������ˡ�
}

int main() {
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        if (s == 'H') {
            int x;
            cin >> x;
            insert_to_head(x);
        } else if (s == 'D') {
            int k;
            cin >> k;
            remove(k);
        } else if (s == 'I') {
            int k, x;
            cin >> k >> x;
            add(k, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
}
