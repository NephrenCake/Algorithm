#include <iostream>

using namespace std;

int n, a, ans;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        ans = 0;
        while (a) {
            a -= (a & -a);
            ans++;
        }
        cout << ans << " ";
    }
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 1e5 + 10;
// int n, a;
//
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a;
//         int ans = 0;
//         while (a) {
//             if (a & 1) ans++;
//             a >>= 1;
//         }
//         cout << ans << " ";
//     }
// }
