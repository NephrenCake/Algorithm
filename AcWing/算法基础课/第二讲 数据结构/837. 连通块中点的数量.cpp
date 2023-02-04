#include <iostream>

using namespace std;

const int N = 100010;
int n, m, p[N], s[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i, s[i] = 1;

    while (m--) {
        string str;
        int a, b;
        cin >> str;
        if (str == "C") {
            cin >> a >> b;
            if (find(a) == find(b)) continue;  // 同一个集合不需要相加
            s[find(b)] += s[find(a)];  // 先处理size再合并
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
