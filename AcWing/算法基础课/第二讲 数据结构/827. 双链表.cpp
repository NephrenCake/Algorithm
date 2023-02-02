#include <iostream>

using namespace std;

const int N = 100010;
int head = 0, tail = 1, l[N] = {-1, 0}, r[N] = {1, -1}, e[N], idx = 2;

void L(int x) {  // �����������˲����� x
    e[idx] = x, l[idx] = head, r[idx] = r[head];
    r[l[idx]] = idx, l[r[idx]] = idx;
    idx++;
}

void R(int x) {  // ����������Ҷ˲����� x
    e[idx] = x, l[idx] = l[tail], r[idx] = tail;
    r[l[idx]] = idx, l[r[idx]] = idx;
    idx++;
}

void D(int k) {  // ���� k ���������ɾ��
    int p = l[k], q = r[k];
    r[p] = q, l[q] = p;
}

void IL(int k, int x) {  // �ڵ� k ���������������һ����
    e[idx] = x, l[idx] = l[k], r[idx] = k;
    r[l[idx]] = idx, l[r[idx]] = idx, idx++;
}

void IR(int k, int x) {  // �ڵ� k ����������Ҳ����һ����
    IL(r[k], x);
}

int main() {
    int m, k, x;
    string c;
    cin >> m;
    while (m--) {
        cin >> c;
        if (c == "L") {
            cin >> x;
            L(x);
        } else if (c == "R") {
            cin >> x;
            R(x);
        } else if (c == "D") {
            cin >> k;
            D(k + 1);
        } else if (c == "IL") {
            cin >> k >> x;
            IL(k + 1, x);
        } else if (c == "IR") {
            cin >> k >> x;
            IR(k + 1, x);
        }
    }
    for (int i = r[head]; i != tail; i = r[i])
        cout << e[i] << " ";
}
