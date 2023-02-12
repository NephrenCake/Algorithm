#include <iostream>

using namespace std;

string dfs(int x) {
    string res;
    for (int i = 15; i >= 0; i--)
        if (x >> i & 1) {
            if (i == 0) res += "2(0)";
            else if (i == 1) res += "2";
            else res += "2(" + dfs(i) + ")";
            res += "+";
        }
    return res.substr(0, res.size() - 1);
}

int main() {
    int n;
    while (cin >> n)
        cout << dfs(n) << endl;
}
