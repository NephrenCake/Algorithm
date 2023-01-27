#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 100010;
int n, a[N], ans;
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0, j = 0; j < n;) {
        while (s.count(a[j]) == 0 && j < n)
            s.insert(a[j++]);

        ans = max(ans, j - i);

        while (s.count(a[j]) != 0 && i < j)
            s.erase(a[i++]);
    }

    cout << ans;
}
