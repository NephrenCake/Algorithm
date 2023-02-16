#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 5010;
int n, m, ans;
string b;
unordered_set<string> used, a;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a.insert(s);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b;
        if (a.count(b) == 0) continue;
        if (used.count(b) == 0)
            used.insert(b);
        if (used.size() == n) {
            if (n != 1) {
                used.clear();
                used.insert(b);
                ans++;
            } else {
                ans = -1;
                break;
            }
        }
    }
    cout << ans;
}
