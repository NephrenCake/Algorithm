#include <iostream>
#include <vector>

using namespace std;

int div(vector<int> &a) {
    int t = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        t = t * 10 + a[i];
        a[i] = t / 2;
        t %= 2;
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    return t;
}

int main() {
    cin.sync_with_stdio(false);
    string s;
    vector<int> a;
    while (cin >> s) {
        if (s == "0") {
            cout << 0 << endl;
            continue;
        }
        a.clear();
        for (int i = s.size() - 1; i >= 0; i--) a.push_back(s[i] - '0');
        string ans = "";
        while (!(a.size() == 1 && a[0] == 0)) {
            int t = div(a);
            ans = to_string(t) + ans;
        }
        cout << ans << endl;
    }
}
