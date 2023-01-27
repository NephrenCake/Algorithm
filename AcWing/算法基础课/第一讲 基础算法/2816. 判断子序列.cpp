#include <iostream>

using namespace std;

const int N = 100010;
int n, m, a[N], b[N], j;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (j < n && b[i] == a[j])
            j++;
    }
    if (j == n) cout << "Yes";
    else cout << "No";
}
