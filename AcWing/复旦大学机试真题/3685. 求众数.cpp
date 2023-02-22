#include <iostream>
#include <map>

using namespace std;

int n, a;
map<int, int> m;

int main() {
    cin >> n;
    while (n-- && cin >> a) m[a]++;
    int ans, val = 0;
    for (auto [k, v]: m)
        if (v > val)
            ans = k, val = v;
    cout << ans;
}
