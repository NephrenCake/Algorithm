#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> tb;

bool dfs(int idx, int sum) {
    if (sum == n) return true;
    if (idx == tb.size()) return false;
    return dfs(idx + 1, sum) || dfs(idx + 1, sum + tb[idx]);
}

int main() {
    tb.push_back(1);
    for (int i = 1; tb[i - 1] <= 1e6 / i; i++)
        tb.push_back(tb[i - 1] * i);

    while (cin >> n, n >= 0)
        if (dfs(0, 0) && n != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
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
