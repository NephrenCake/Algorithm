#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 10000 + 10;

int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int p = max(n - i, i - 1);
        cout << p * 2 << endl;
    }

    return 0;
}
