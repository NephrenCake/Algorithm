#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m;
vector<int> v[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);  // 该电脑延迟 v[x].size()
    }

    for (int i = 0; i < m; i++) {

    }
    return 0;
}
/*
4 3
1 2
1 3
2 4
2 3
3 4
3 3

 */
