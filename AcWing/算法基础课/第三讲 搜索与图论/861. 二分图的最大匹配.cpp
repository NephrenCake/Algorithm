#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 510;
int n1, n2, m, match[N], used[N], ans;
vector<int> v[N];

bool find(int x) {
    for (auto ne: v[x]) {
        if (!used[ne]) {
            used[ne] = 1;
            if (!match[ne] || find(match[ne])) {
                match[ne] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    for (int i = 1, a, b; i <= m; i++) cin >> a >> b, v[a].push_back(b);

    for (int i = 1; i <= n1; i++) {
        memset(used, 0, sizeof used);
        if (find(i)) ans++;
    }
    cout << ans;
}
