#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p) {  // a^b%p
    int res = 1;
    while (b) {
        if (b & 1) res = (LL) res * a % p;
        b >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, a, b, p;
    cin >> n;
    while (n--) {
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
}
