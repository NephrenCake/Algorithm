#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> n_map, a_map;
int n, a, ans = 0x3f3f3f3f;

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
    for (auto [k, v]: a_map){  // ×¢ÒâÓï·¨ÊÇc++17
        // cout << k << " " << v << " " << n_map[k] << endl;
        ans = min(ans, n_map[k] / v);
    }
    cout << ans;
}
