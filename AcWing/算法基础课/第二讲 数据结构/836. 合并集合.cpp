#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, p[N];
string s;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        cin >> s >> a >> b;
        if (s == "M") {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
