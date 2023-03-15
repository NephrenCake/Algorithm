#include <iostream>

using namespace std;

int n, a;

int main() {
    while (cin >> n) {
        int minv = 0x3f3f3f3f, maxv = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            minv = min(minv, a);
            maxv = max(maxv, a);
        }
        cout << maxv << " " << minv << endl;
    }
}
