#include <iostream>
#include <vector>

using namespace std;

struct P {
    int p, d;
};
const int N = 1e5 + 10;
int n, m, a, b;
vector<int> v[N];
P q[N];
int hh = 0, tt = -1;
bool used[N];

int main() {
    cin >> n >> m;
    while (cin >> a >> b)
        v[a].push_back(b);

    q[++tt] = {1, 0};
    while (hh <= tt) {
        P cur = q[hh++];
        if (cur.p == n) {
            cout << cur.d;
            return 0;
        }
        for (auto next : v[cur.p])
            if (!used[next]) {
                used[next] = true;
                q[++tt] = {next, cur.d + 1};
            }
    }
    cout << -1;
}
