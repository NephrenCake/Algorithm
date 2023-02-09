#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N  = 510;
int n1, n2, m, match[N], used[N], ans;
vector<int> v[N];

bool find(int idx) {
    for (int i: v[idx]) {
        if (used[i] == 0) {
            used[i] = 1;
            if (!match[i] || find(match[i])) {
                match[i] = idx;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = 1; i <= n1; i++) {
        memset(used, 0, sizeof used);
        if (find(i))
            ans++;
    }
    cout << ans;
}
