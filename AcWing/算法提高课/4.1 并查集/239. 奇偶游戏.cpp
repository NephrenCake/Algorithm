#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, a, b;
string s;
unordered_map<int, int> p, d;

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 2;
        p[x] = t;
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> s;
        a--;
        if (p.find(a) == p.end()) p[a] = a, d[a] = 0;
        if (p.find(b) == p.end()) p[b] = b, d[b] = 0;
        int rel = s == "odd" ? 1 : 0;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            d[pa] = d[b] - d[a] + rel;
            p[pa] = pb;
        } else {
            if (((d[a] - d[b]) % 2 + 2) % 2 != rel) {
                cout << i - 1;
                return 0;
            }
        }
    }
    cout << m;
}
