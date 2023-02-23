#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, p[N], d[N];
string s;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i, d[i] = 1;
    while (m-- && cin >> s)
        if (s == "C") {
            cin >> a >> b;
            if (find(a) == find(b)) continue;
            d[find(b)] += d[find(a)];
            p[find(a)] = b;
        } else if (s == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout <<"No" << endl;
        } else if (s == "Q2") {
            cin >> a;
            cout << d[find(a)] << endl;
        }
}
