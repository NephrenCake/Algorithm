#include <iostream>

using namespace std;

int n, m;

int main() {
    while (cin >> n >> m) {
        // 画图找规律
        // 1. 当n == 1 && m == 1时, 满足题意
        // 2. 当m == 1 || n == 1时,不满足题意
        // 3. 当n和m同时为奇数,不满足题意
        // 4. 当m和n不同时为奇数,并且 m > 1 && n > 1,满足题意
        if (n == 1 && m == 1) cout << "Y" << endl;
        else if (n == 1 || m == 1) cout << "N" << endl;
        else if (n % 2 == 1 && m % 2 == 1) cout << "N" << endl;
        else cout << "Y" << endl;
    }
}
