#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1561/

int main() {
    string s;
    cin >> s;  // +1.23400E-03
    int e_pos = s.find('E');

    string a_str = s[1] + s.substr(3, e_pos - 3);  // 有效部分无小数
    int bv = stoi(s.substr(e_pos + 2));  // 指数部分数值

    string res;
    if (s[0] == '-') res += '-';  // 单独为负数加负号
    if (bv == 0) {
        cout << res + s.substr(1, e_pos - 1);
        return 0;
    }
    if (s[e_pos + 1] == '-') {
        res += "0.";
        while (--bv) res += '0';  // 为小数加前导零
        res += a_str;
    } else {
        bv = bv + 1;
        if (bv >= a_str.size()) {
            bv -= a_str.size();
            while (bv--)
                a_str += '0';
        } else
            a_str.insert(bv, ".");
        res += a_str;
    }
    cout << res;
}
