#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1502/

string str;
vector<int> val;
vector<int> res;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        val.push_back(str[str.size() - 1 - i] - '0');

    int t = 0, v;
    for (int i : val) {
        v = i * 2 + t;
        t = v / 10;
        res.push_back(v % 10);
    }
    if (t == 1) res.push_back(1);

    vector<int> c = res;
    sort(c.begin(), c.end());
    sort(val.begin(), val.end());

    if (c == val) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
}
