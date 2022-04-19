#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1536/

string s1, s2, res;
unordered_map<char, bool> exist;

int main() {
    getline(cin, s1);
    getline(cin, s2);
    for (auto& c: s2)
        exist[c] = true;
    for (auto& c: s1)
        if (exist.find(c) == exist.end())
            res += c;
    cout << res;
}
