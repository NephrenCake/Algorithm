#include <iostream>

using namespace std;

const int N = 100010;
int n, m, p[N];

int find(int a) {
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;

    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        if (s == "M") p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
