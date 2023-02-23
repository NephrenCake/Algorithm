#include <iostream>

using namespace std;

const int N = 100010;
int e[N], ne[N], idx = 1;

void insert(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void del(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int n, x, k;
    string s;
    cin >> n;
    while (n-- && cin >> s)
        if (s == "H") {
            cin >> x;
            insert(0, x);
        } else if (s == "I") {
            cin >> k >> x;
            insert(k, x);
        } else if (s == "D") {
            cin >> k;
            del(k);
        }
    for (int i = ne[0]; i != 0; i = ne[i])
        cout << e[i] << " ";
}
