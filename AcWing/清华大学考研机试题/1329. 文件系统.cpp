#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;
int n, ans;
vector<int> v[N];
string s[N];

void dfs(int cur, int len) {
    len += s[cur].size() + 1;
    ans += len;
    for (int ne: v[cur])
        dfs(ne, len);
}

int main() {
    cin >> n;
    for (int i = 1, fa; i <= n; i++) {
        cin >> fa >> s[i];
        v[fa].push_back(i);
    }
    for (int ne: v[0])
        dfs(ne, 0);
    cout << ans;
}
