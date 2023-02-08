#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

struct P {
    string s;
    int x, y, d;
};
queue<P> q;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
unordered_set<string> used;

int main() {
    q.push({"", 0, 0, 0});
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            q.front().s += c;
            if (c == 'x')
                q.front().x = i, q.front().y = j;
        }
    used.insert(q.front().s);

    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        if (cur.s == "12345678x") {
            cout << cur.d;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i], y = cur.y + dy[i];
            if (!(0 <= x && x < 3 && 0 <= y && y < 3)) continue;
            int a = x * 3 + y, b = cur.x * 3 + cur.y;
            string s = cur.s;
            swap(s[a], s[b]);
            if (used.find(s) == used.end()) {
                used.insert(s);
                q.push({s, x, y, cur.d + 1});
            }
        }
    }
    cout << -1;
}
