#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef unsigned long long ULL;
const int N = 55;
int n;
VI w[N * 2], f[N * 2][N * 2], ans, INF;

void makeINF(VI &a) {
    a.clear();
    for (int i = 1; i <= 29; i++) a.push_back(0);
    a.push_back(1);
}

void int2vi(VI &a, int b) {
    while (b) a.push_back(b % 10), b /= 10;
}

VI minVI(VI &a, VI &b) {
    if (a.size() < b.size()) return a;
    else if (a.size() > b.size()) return b;
    else
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] < b[i]) return a;
            else if (a[i] > b[i]) return b;
    return a;
}

VI addVI(VI &a, VI &b) {
    VI c;
    int t = 0;
    for (ULL i = 0; i < max(a.size(), b.size()); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t);
    return c;
}

VI mulVI(VI &a, VI &b) {
    VI c = VI(a.size() + b.size(), 0);
    for (ULL i = 0; i < a.size(); i++)
        for (ULL j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    int t = 0;
    for (ULL i = 0; i < c.size(); i++) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

void printVI(VI &a) {
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];
}

int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        int2vi(w[i], t);
        int2vi(w[i + n], t);
    }

    makeINF(INF);
    ans = INF;
    for (int len = 3; len <= n; len++)
        for (int i = 1; i + len - 1 < 2 * n; i++) {
            int j = i + len - 1;
            f[i][j] = INF;
            for (int k = i + 1; k < j; k++) {
                VI t = mulVI(w[i], w[k]);
                t = mulVI(t, w[j]);
                t = addVI(t, f[i][k]);
                t = addVI(t, f[k][j]);
                f[i][j] = minVI(f[i][j], t);
            }
            if (len == n)
                ans = minVI(ans, f[i][j]);
        }
    printVI(ans);
}
