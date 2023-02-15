#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;
int n, m, x, a[N], b;
unordered_map<int, int> map;

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map.insert({a[i], i});
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        if (map.find(x - b) != map.end()) {
            cout << map[x - b] << " " << i;
            return 0;
        }
    }
}

// #include <iostream>
//
// using namespace std;
//
// const int N = 1e5 + 10;
// int n, m, x, a[N], b[N];
//
// int find(int tar) {
//     int l = -1, r = m, mid;
//     while (l < r) {
//         mid = (l + r + 1) / 2;
//         if (b[mid] < tar) l = mid;
//         else r = mid - 1;
//     }
//     return r + 1;
// }
//
// int main() {
//     cin >> n >> m >> x;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < m; i++) cin >> b[i];
//
//     for (int i = 0; i < n; i++) {
//         int j = find(x - a[i]);
//         if (b[j] == x - a[i]) {
//             cout << i << " " << j;
//             break;
//         }
//     }
// }
