#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 15;
int n, a[N], g[N], used[N], ans;
unordered_set<int> s;

void dfs(int cur) {
    if (cur == n + 1) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++){
        if (!used[i - 1] && a[i] == a[i - 1]) continue;
        if (!used[i] && s.count(a[i] + g[cur - 1])) {
            used[i] = true;
            g[cur] = a[i];
            dfs(cur + 1);
            used[i] = false;
        }
    }
}

int main() {
    for (int i = 0; i <= 100000; i++)
        if ((long long)i * i <= 0x7f7f7f7f)
            s.insert(i * i);
        else
            break;

    cin >> n;
    a[0] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        used[i] = true;
        g[1] = a[i];
        dfs(2);
        used[i] = false;
    }
    cout << ans;
}

// #include <iostream>
// #include <algorithm>
// #include <unordered_set>
//
// using namespace std;
//
// const int N = 15;
// int n, a[N], g[N], used[N], ans;
// unordered_set<int> s;
//
// void dfs(int cur) {
//     if (cur == n + 1) {
//         ans++;
//         return;
//     }
//
//     for (int i = 1; i <= n; i++){
//         if (!used[i - 1] && a[i] == a[i - 1]) continue;
//         if (!used[i] && s.count(a[i] + g[cur - 1])) {
//             used[i] = true;
//             g[cur] = a[i];
//             dfs(cur + 1);
//             used[i] = false;
//         }
//     }
// }
//
// int main() {
//     for (int i = 0; i <= 100000; i++)
//         if ((long long)i * i <= 2e9)
//             s.insert(i * i);
//         else
//             break;  // 0也是完全平方数，两者和为完全平方数，所以上限要到2e9
//
//     cin >> n;
//     a[0] = -1;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//
//     sort(a + 1, a + 1 + n);
//
//     for (int i = 1; i <= n; i++) {
//         if (a[i] == a[i - 1]) continue;
//         used[i] = true;
//         g[1] = a[i];
//         dfs(2);
//         used[i] = false;
//     }
//     cout << ans;
// }
