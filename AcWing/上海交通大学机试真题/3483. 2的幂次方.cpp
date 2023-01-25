#include <iostream>

using namespace std;


string dfs(int n) {
    if (n == 0)
        return "0";

    string res = "";
    for (int i = 14; i >= 0; i--)
        if (n >> i & 1) {
            if (i == 1)
                res += "2";
            else
                res += "2(" + dfs(i) + ")";
            res += "+";
        }
    return res.substr(0, res.size() - 1);
}

int main() {
    int n;
    while (cin >> n)
        cout << dfs(n) << endl;
}
