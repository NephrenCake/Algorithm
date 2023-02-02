#include <iostream>

using namespace std;

const int N = 100010;
int head = -1, e[N], ne[N], idx;

// 向链表头插入一个数 x
void add(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x) {
    e[idx] = x, ne[idx] = ne[k - 1], ne[k - 1] = idx++;
}

void del(int k) {
    if (k == 0) head = ne[head];
    else ne[k - 1] = ne[ne[k - 1]];
}

int main() {
    int m, a, b;
    char c;
    cin >> m;
    while (m--) {
        cin >> c;
        switch (c) {
            case 'H':
                cin >> a;
                add(a);
                break;
            case 'I':
                cin >> a >> b;
                insert(a, b);
                break;
            case 'D':
                cin >> a;
                del(a);
                break;
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
}
