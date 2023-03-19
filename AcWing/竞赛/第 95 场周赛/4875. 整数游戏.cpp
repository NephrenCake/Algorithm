#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int t, n, m, a[N];

int main() {
    cin >> t;
    while (t-- && cin >> n) {
        m = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
            cin >> a[i], m = min(m, a[i]);
        if (a[0] != m) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}
