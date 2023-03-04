#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;
int p, n, m, a;
priority_queue<int, vector<int>, greater<int>> up;
priority_queue<int, vector<int>, less<int>> down;

int main() {
    cin >> p;
    while (p-- && cin >> n >> m) {
        up = priority_queue<int, vector<int>, greater<int>>();
        down = priority_queue<int, vector<int>, less<int>>();
        cout << n << " " << (m + 1) / 2 << endl;
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cin >> a;
            if (down.empty() || a <= down.top()) down.push(a);
            else up.push(a);
            if (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }
            if (up.size() + 1 < down.size()) {
                up.push(down.top());
                down.pop();
            }
            if (i & 1) cnt++, cout << down.top() << " ";
            if (cnt == 10) cnt = 0, cout << endl;
        }
        if (cnt != 0) cout << endl;
    }
}
