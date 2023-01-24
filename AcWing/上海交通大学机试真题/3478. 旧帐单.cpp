#include <iostream>
#include <algorithm>

using namespace std;

int n, x, y, z;

void sol() {
    for (int i = 9; i; i--)
        for (int j = 9; j >= 0; j--) {
            int t = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
            if (t % n == 0) {
                cout << i << " " << j << " " << t / n << endl;
                return;
            }
        }
    cout << 0 << endl;
}

int main() {
    while (cin >> n >> x >> y >> z)
        sol();
}
