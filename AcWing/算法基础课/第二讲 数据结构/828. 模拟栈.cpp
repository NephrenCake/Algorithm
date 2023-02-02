#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], tt = -1;

int main() {
    int m, x;
    string c;
    cin >> m;
    while (m--) {
        cin >> c;
        if (c == "push") {
            cin >> x;
            stk[++tt] = x;
        } else if (c == "pop") {
            tt--;
        } else if (c == "empty") {
            if (tt == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (c == "query") {
            cout << stk[tt] << endl;
        }
    }
}
