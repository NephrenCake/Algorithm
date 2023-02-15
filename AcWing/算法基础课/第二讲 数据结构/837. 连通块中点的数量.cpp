#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, p[N], s[N];
string str;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i, s[i] = 1;
    while (m--) {
        cin >> str;
        if (str == "C") {
            cin >> a >> b;
            if (find(a) == find(b)) continue;
            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
        } else if (str == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            cin >> a;
            cout << s[find(a)] << endl;
        }
    }
}
