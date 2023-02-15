#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0, j = 0; i < n; ) {
        while (j < m && a[i] != b[j]) j++;
        if (j == m) {
            cout << "No";
            return 0;
        }
        i++, j++;
    }
    cout << "Yes";
}
