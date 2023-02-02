#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], hh = 0, tt = -1;

int main() {
    int m, x;
    string c;
    cin >> m;
    while (m--) {
        cin >> c;
        if (c == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (c == "pop") {
            hh++;
        } else if (c == "empty") {
            if (hh > tt) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (c == "query") {
            cout << q[hh] << endl;
        }
    }
}
