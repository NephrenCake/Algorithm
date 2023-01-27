#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;
int n, m, x, a[N], b;
unordered_map<int, int> map;

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map.insert({a[i], i});
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        if (map.find(x - b) != map.end()) {
            cout << map[x - b] << " " << i;
            return 0;
        }
    }
}
