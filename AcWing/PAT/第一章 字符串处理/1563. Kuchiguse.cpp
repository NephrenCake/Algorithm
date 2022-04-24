#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1565/

const int N = 110;

int n, min_len = 1e4;
string s[N], ans;

int main() {
    cin >> n;
    getline(cin, s[0]);  // 注意，换行符会被getline捕获
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        min_len = min(min_len, (int) s[i].size());
    }

    for (int i = 1; i <= min_len; i++) {
        char c = s[0][s[0].size() - i];
        bool match_all = true;
        for (int j = 1; j < n; j++)
            if (c != s[j][s[j].size() - i]) {
                match_all = false;
                break;
            }
        if (match_all) ans = c + ans;
        else break;
    }
    if (ans.empty()) cout << "nai";
    else cout << ans;
}
