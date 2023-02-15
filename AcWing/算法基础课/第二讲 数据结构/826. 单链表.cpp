#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h, e[N], ne[N], idx = 1;  // hΪͷָ�룬0ֵ��ʾ�սڵ㣬idx��ʾ��1��ʼ����ռ�

void add(int x) {  // ͷ�巨��������ͷָ��ı�
    e[idx] = x, ne[idx] = h, h = idx++;
}

void del(int k) {  // ɾ����k����������������
    if (k == 0) h = ne[h];
    else ne[k] = ne[ne[k]];
}

void insert(int k, int x) {  // �ڵ�k����������������x
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

int main() {
    string s;
    int n, x, k;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "H") {
            cin >> x;
            add(x);
        } else if (s == "D") {
            cin >> k;
            del(k);
        } else if (s == "I") {
            cin >> k >> x;
            insert(k, x);
        }
    }
    for (int i = h; i; i = ne[i])
        cout << e[i] << " ";
}
