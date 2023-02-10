#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> n_map, a_map;
int n, a;

void get_div(int x, unordered_map<int, int> &map) {
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) x /= i, map[i]++;
    if (x > 1) map[x]++;
}

int main() {
    cin >> n >> a;
    for (int i = n; i > 1; i--)
        get_div(i, n_map);
    get_div(a, a_map);
    int ans = 0x3f3f3f3f;
    for (auto ai: a_map) {
        // cout << ai.first << " " << ai.second << " " << n_map[ai.first] << endl;
        ans = min(ans, n_map[ai.first] / ai.second);
    }
    cout << ans;
}
