#include <iostream>

using namespace std;

const int N = 1e5 + 10, P = 131;
string s;
int n, m;
unsigned long long a[N], e[N] = {1};

int main() {
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] * P + s[i], e[i] = e[i - 1] * P;
    for (int i = 1, l1, r1, l2, r2; i <= m; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (a[r1] - a[l1 - 1] * e[r1 - l1 + 1] == a[r2] - a[l2 - 1] * e[r2 - l2 + 1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
