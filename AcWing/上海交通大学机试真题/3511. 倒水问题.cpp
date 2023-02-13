#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> used;
set<int> ans;
int A, B, C;

void dfs(int a, int b, int c) {
    if (used.find({a, b}) != used.end()) return;
    used.insert({a, b});
    if (ans.find(c) == ans.end()) ans.insert(c);

    int d;
    // a -> b
    d = min(a, B - b);
    dfs(a - d, b + d, c);
    // b -> a
    d = min(b, A - a);
    dfs(a + d, b - d, c);
    // a -> c
    d = min(a, C - c);
    dfs(a - d, b, c + d);
    // c -> a
    d = min(c, A - a);
    dfs(a + d, b, c - d);
    // b -> c
    d = min(b, C - c);
    dfs(a, b - d, c + d);
    // c -> b
    d = min(c, B - b);
    dfs(a, b + d, c - d);
}

int main() {
    while (cin >> A >> B >> C) {
        used.clear();
        ans.clear();
        dfs(0, 0, C);
        cout << ans.size() << endl;
    }
}
