#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int n;
string s;
queue<pair<string, int>> q;
unordered_set<string> st;

int main() {
    cin >> n >> s;
    // basic check
    int mp[3] = {};
    for (auto c: s) mp[c - '0']++;
    if (mp[0] < 1 || mp[1] < 1 || mp[2] < 2) {
        cout << -1;
        return 0;
    }
    // bfs
    q.push({s, 0});
    st.insert(s);
    while (q.size()) {
        string cur = q.front().first;
        int lv = q.front().second;
        q.pop();
        if (cur.find("2012") != -1) {
            cout << lv;
            return 0;
        }
        for (int i = 0; i + 1 < cur.size(); i++) {
            string t = cur;
            swap(t[i], t[i + 1]);
            if (st.find(t) == st.end())
                q.push({t, lv + 1}), st.insert(t);
        }
    }
}
