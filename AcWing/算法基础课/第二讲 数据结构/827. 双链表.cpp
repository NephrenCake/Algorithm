#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h, e[N], l[N], r[N], idx = 1;

void del(int k) {
    r[l[k]] = r[k], l[r[k]] = l[k];
}

void insert(int k, int x) {
    e[idx] = x, l[idx] = k, r[idx] = r[k], r[l[idx]] = idx, l[r[idx]] = idx, idx++;
}

int main() {
    int n, k, x;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "L") {
            cin >> x;
            insert(0, x);
        } else if (s == "R") {
            cin >> x;
            insert(l[0], x);
        } else if (s == "D") {
            cin >> k;
            del(k);
        } else if (s == "IL") {
            cin >> k >> x;
            insert(l[k], x);
        } else if (s == "IR") {
            cin >> k >> x;
            insert(k, x);
        }
    }
    for (int i = r[h]; i; i = r[i])
        cout << e[i] << " ";
}
