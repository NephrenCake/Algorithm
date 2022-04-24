#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1572/

string n, m, ans;
unordered_set<char> keys;
int i = 0, j = 0;

int main() {
    cin >> n >> m;
    n += '#', m += '#';
    while (i < n.size() && j < m.size()) {
        if (n[i] == m[j]) i++, j++;
        else {
            char ch = n[i];
            if (ch >= 'a' && ch <= 'z') ch += 'A' - 'a';
            if (keys.count(ch) == 0) {
                keys.insert(ch);
                ans += ch;
            }
            i++;
        }
    }
    cout << ans;
}
