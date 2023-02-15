#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h, e[N], ne[N], idx = 1;  // h为头指针，0值表示空节点，idx表示从1开始分配空间

void add(int x) {  // 头插法，将导致头指针改变
    e[idx] = x, ne[idx] = h, h = idx++;
}

void del(int k) {  // 删除第k个插入的数后面的数
    if (k == 0) h = ne[h];
    else ne[k] = ne[ne[k]];
}

void insert(int k, int x) {  // 在第k个插入的数后面插入x
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
