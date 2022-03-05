// 法一：暴力
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> dis;  // [dis1, dis2]
long long ans = LLONG_MAX;  // 下次不要用 LONG_MAX，不够大

int main() {
    long long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    dis.push_back({0, 0});  // 考虑一个半径为0
    for (long long i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        dis.push_back({(a - x1) * (a - x1) + (b - y1) * (b - y1),
                       (a - x2) * (a - x2) + (b - y2) * (b - y2)});
    }

    for (long long i = 0; i < n + 1; ++i) {  // 关注边界轮廓的变化
        long long r1 = dis[i][0];
        long long r2 = 0;
        for (long long j = 1; j < n + 1; ++j)
            if (dis[j][0] > r1 && dis[j][1] > r2)
                r2 = dis[j][1];
        ans = min(ans, r1 + r2);
    }
    cout << ans;
}

// 法二
// #include <iostream>
// #include <vector>
// #include <algorithm>
//
// using namespace std;
//
// vector<vector<long long>> dis;  // [dis1, dis2]
// long long ans = 10e18;
//
// int main() {
//     long long n, x1, y1, x2, y2;
//     cin >> n >> x1 >> y1 >> x2 >> y2;
//     dis.push_back({0, 0});  // 考虑一个半径为0
//     for (long long i = 0; i < n; ++i) {
//         long long a, b;
//         cin >> a >> b;
//         dis.push_back({(a - x1) * (a - x1) + (b - y1) * (b - y1),
//                        (a - x2) * (a - x2) + (b - y2) * (b - y2)});
//     }
//     dis.push_back({0, 0});  // 考虑一个半径为0
//
//     sort(dis.begin(), dis.end() - 1,
//          [](vector<long long>& a, vector<long long>& b) {
//              if (a[0] == b[0])
//                  return a[1] < b[1];
//              return a[0] < b[0];
//          });
//
//     for (long long i = n; i >= 1; i--)
//         dis[i][1] = max(dis[i + 1][1], dis[i][1]);
//
//     ans = dis[1][1];
//     for (long long i = 1; i < n + 1; i++)
//         ans = min(ans, dis[i][0] + dis[i + 1][1]);
//
//     cout << ans;
// }