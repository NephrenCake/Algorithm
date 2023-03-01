#include <iostream>

using namespace std;

const int N = 30010;
int p[N], d[N], cnt[N];

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    for (int i = 1; i < N; i++) p[i] = i, cnt[i] = 1;
    int t, a, b;
    string s;
    cin >> t;
    while (t-- && cin >> s >> a >> b) {
        int pa = find(a), pb = find(b);
        if (s == "M") {
            if (pa == pb) continue;
            d[pa] = cnt[pb];
            cnt[pb] += cnt[pa];
            p[pa] = pb;
        } else {
            if (a == b)
                cout << 0 << endl;
            else if (pa == pb)
                cout << abs(d[a] - d[b]) - 1 << endl;
            else
                cout << -1 << endl;
        }
    }
}
