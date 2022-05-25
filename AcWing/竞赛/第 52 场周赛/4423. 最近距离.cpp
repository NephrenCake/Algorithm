#include <iostream>
#include <queue>

using namespace std;

// https://www.acwing.com/problem/content/4426/

const int N = 2 * 1e5 + 10;

int n, ans[N];
bool visited[N];
queue <pair<int, int>> q;
int dx[] = {-1, 1};

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            q.push({0, i}); // lv, ptr
            visited[i] = true;
            ans[i] = 0;
        }
    }
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int ptr = t.second;
        for (int i = 0; i < 2; i++) {
            int nx = dx[i] + ptr;
            if (0 < nx && nx <= n && !visited[nx]) {
                q.push({t.first + 1, nx});
                visited[nx] = true;
                ans[nx] = t.first + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
