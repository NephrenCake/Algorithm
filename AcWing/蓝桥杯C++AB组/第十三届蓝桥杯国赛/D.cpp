#include <bits/stdc++.h>

using namespace std;

string N, ans;
int a, b;

void dfs(string s, int a_, int b_, int idx) {
    if (s > ans) {
        ans = s;
        // cout << "ans " << ans << endl;
    }
    if (a_ == 0 && b_ == 0 || idx == N.length())
        return;

    int cur_val = s[idx] - '0';
    int op_a = 9 - cur_val, op_b = cur_val + 1;  // ->9所需次数

    // cout << " idx " << idx << " op_a " << op_a << " op_b " << op_b << endl;
    // a
    int change = min(op_a, a_);
    s[idx] = cur_val + change + '0';
    // cout << " a: cur_val " << cur_val << " -> " << s[idx] << endl;
    dfs(s, a_ - change, b_, idx + 1);
    s[idx] = cur_val + '0';
    // b
    if (op_b <= b_) {
        s[idx] = '9';
        // cout << " b: cur_val " << cur_val << " -> " << s[idx] << endl;
        dfs(s, a_, b_ - op_b, idx + 1);
    }
}

int main() {
    cin >> N >> a >> b;
    ans = N;
    dfs(N, a, b, 0);
    cout << ans;
    return 0;
}
/*
123 3 5

 */
