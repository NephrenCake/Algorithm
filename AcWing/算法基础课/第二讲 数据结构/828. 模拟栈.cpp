#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], tt = -1;

int main() {
    int n, x;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            stk[++tt] = x;
        } else if (s == "pop") {
            tt--;
        } else if (s == "empty") {
            if (tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else if (s == "query") {
            cout << stk[tt] << endl;
        }
    }
}
