#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, cnt;
string a[N], t, ans = "";

int dfs(int idx) {
    cout << ans << endl;
    if (idx > cnt) return idx;  // 错误时返回越界值
    if (a[idx] == "int") {
        ans += "int";
        return idx;
    }
    ans += a[idx] + "<";
    idx = dfs(idx + 1);
    ans += ",";
    idx = dfs(idx + 1);
    ans += ">";
    return idx;
}

int main() {
    cin >> n;
    while (cin >> t) a[++cnt] = t;
    int idx = dfs(1);
    if (idx == cnt) cout << ans;
    else cout << "Error occurred";
}
