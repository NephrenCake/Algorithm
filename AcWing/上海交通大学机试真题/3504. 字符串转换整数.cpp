#include <iostream>

using namespace std;

long long ans, flag;
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= '9' && '0' <= s[i]) {
            flag = 1;
            ans = ans * 10 + s[i] - '0';
            if (ans > INT32_MAX) {
                ans = -1;
                break;
            }
        } else
        if (flag) break;
    }
    if (flag) cout << ans;
    else cout << -1;
}
