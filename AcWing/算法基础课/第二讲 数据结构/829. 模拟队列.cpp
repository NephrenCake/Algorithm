#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], hh = 0, tt = -1;

int main() {
    string s;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (s == "pop") {
            hh++;
        } else if (s == "empty") {
            if (hh <= tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else if (s == "query") {
            cout << q[hh] << endl;
        }
    }
}
