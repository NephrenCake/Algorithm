#include <iostream>

using namespace std;

int a[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
int n;

bool dfs(int num, int cur) {
    if (cur == 11) {
        if (num == n && num != 0)
            return true;
        else
            return false;
    }

    return dfs(num + a[cur], cur + 1) || dfs(num, cur + 1);
}

int main() {
    while (cin >> n, n >= 0) {
        if (dfs(0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// #include <iostream>
//
// using namespace std;
//
// int a[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
// int n;
//
// void sol() {
//     for (int i = 0; i < 1 << 11; i++) {
//         int sum = 0;
//         for (int j = 0; j <= 10; j++)
//             if (i >> j & 1)
//                 sum += a[j];
//         if (sum == n) {
//             cout << "YES" << endl;
//             return;
//         }
//     }
//     cout << "NO" << endl;
// }
//
// int main() {
//     while (cin >> n, n >= 0)
//         if (n > 0)
//             sol();
//         else
//             cout << "NO" << endl;
// }
