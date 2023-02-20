#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, used[N];
vector<int> v[N];
struct P {
    int i, d;
};
queue<P> q;

int main() {
    cin >> n >> m;
    while (m-- && cin >> a >> b) v[a].push_back(b);

    q.push({1, 0});
    used[1] = 1;
    while (!q.empty()) {
        P cur = q.front();
        q.pop();
        if (cur.i == n) {
            cout << cur.d;
            return 0;
        }
        for (auto ne: v[cur.i])
            if (!used[ne])
                used[ne] = 1, q.push({ne, cur.d + 1});
    }
    cout << -1;
}
