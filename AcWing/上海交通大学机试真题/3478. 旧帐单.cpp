#include <iostream>

using namespace std;

int n, x, y, z;

void sol() {
    for (int i = 9; i >= 1; i--)
        for (int j = 9; j >= 0; j--) {
            int v = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
            if (v % n == 0) {
                cout << i << " " << j << " " << v / n << endl;
                return;
            }
        }
    cout << 0 << endl;
}

int main() {
    while (cin >> n >> x >> y >> z)
        sol();
}
