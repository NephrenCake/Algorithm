#include <iostream>

using namespace std;

int n, a[8], used[8];

void dfs(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!used[i]) {
            used[i] = 1;
            a[idx] = i;
            dfs(idx + 1);
            used[i] = 0;
        }
}

int main() {
    cin >> n;
    dfs(0);
}
