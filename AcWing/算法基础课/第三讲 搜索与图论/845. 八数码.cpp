#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct P {
    string s;
    int x, y, d;
};
queue<P> q;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
unordered_set<string> used;

int main() {
    string a;
    int x, y;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            char t;
            cin >> t;
            a += t;
            if (t == 'x')
                x = i, y = j;
        }

    q.push({a, x, y, 0});
    used.insert(a);
    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        if (cur.s == "12345678x") {
            cout << cur.d;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            string ns = cur.s;
            swap(ns[(cur.x - 1) * 3 + cur.y - 1], ns[(nx - 1) * 3 + ny - 1]);
            if (1 <= nx && nx <= 3 && 1 <= ny && ny <= 3 && used.count(ns) == 0) {
                used.insert(ns);
                q.push({ns, nx, ny, cur.d + 1});
            }
        }
    }
    cout << -1;
}
