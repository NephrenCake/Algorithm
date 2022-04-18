#include <bits/stdc++.h>

// https://www.acwing.com/problem/content/1521/

using namespace std;

typedef pair<string, string> PSS;
const int N = 1010;

unordered_map<char, char> convert{
        {'1', '@'},
        {'0', '%'},
        {'l', 'L'},
        {'O', 'o'},
};
int n, cnt;
PSS lists[N];
vector<int> idx;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lists[i].first >> lists[i].second;
        bool changed = false;
        for (auto& c: lists[i].second)
            if (convert.find(c) != convert.end()) {
                c = convert[c];
                changed = true;
            }
        if (changed) {
            cnt++;
            idx.push_back(i);
        }
    }

    if (cnt == 0) {
        if (n == 1) printf("There is %d account and no account is modified", n);
        else printf("There are %d accounts and no account is modified", n);
        return 0;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << lists[idx[i]].first << " " << lists[idx[i]].second;
        if (i != cnt - 1) cout << endl;
    }
}
