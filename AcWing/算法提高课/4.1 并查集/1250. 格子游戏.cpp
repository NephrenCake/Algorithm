#include <iostream>

using namespace std;

const int N = 40010;
int p[N], ans;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m, x1, y1, x2, y2;
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n * n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> x1 >> y1 >> s;
        if (s == "D") x2 = x1 + 1, y2 = y1;
        else x2 = x1, y2 = y1 + 1;
        int p1 = n * (x1 - 1) + y1, p2 = n * (x2 - 1) + y2;
        // printf("%d %d %d  %d %d %d %d %d \n", x1, y1, p1, x2, y2, p2, find(p1), find(p2));
        if (find(p1) == find(p2) && ans == 0)
            ans = i;
        else p[find(p1)] = find(p2);
    }
    if (ans != 0) cout << ans;
    else cout << "draw";
}
