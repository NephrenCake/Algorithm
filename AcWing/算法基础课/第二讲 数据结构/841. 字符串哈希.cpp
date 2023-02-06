#include <iostream>

using namespace std;

string str;
int n, m, l1, r1, l2, r2;
typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
ULL a[N], p[N] = {1};

ULL query(int l, int r) {
    return a[r] - a[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m >> str;
    str = " " + str;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * P + str[i], p[i] = p[i - 1] * P;
    while (m--, cin >> l1 >> r1 >> l2 >> r2) {
        if (query(l1, r1) == query(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
