#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1521/

typedef pair<string, string> PSS;
const int N = 1010;

unordered_map<char, char> convert{
        {'1', '@'},
        {'0', '%'},
        {'l', 'L'},
        {'O', 'o'},
};
int n, cnt;
vector<PSS> lists;

string change(string pwd) {
    for (auto& c: pwd)
        if (convert.find(c) != convert.end())
            c = convert[c];
    return pwd;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, pwd;
        cin >> name >> pwd;
        string pwd2 = change(pwd);

        if (pwd2 != pwd) {
            cnt++;
            lists.push_back({name, pwd2});
        }
    }

    if (cnt == 0) {
        if (n == 1) printf("There is %d account and no account is modified", n);
        else printf("There are %d accounts and no account is modified", n);
        return 0;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << lists[i].first << " " << lists[i].second;
        if (i != cnt - 1) cout << endl;
    }
}
