#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
char op[N];
int num[N], n = -1, m = -1;
string s;
unordered_map<char, int> priority = {{'+', 1},
                                     {'-', 1},
                                     {'*', 2},
                                     {'/', 2}};

void eval() {
    int b = num[n--], a = num[n--];
    char p = op[m--];
    // cout << a << p << b << endl;
    if (p == '+') num[++n] = a + b;
    if (p == '-') num[++n] = a - b;
    if (p == '*') num[++n] = a * b;
    if (p == '/') num[++n] = a / b;
}

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int t = 0;
            while (i < s.size() && isdigit(s[i])) t = t * 10 + s[i++] - '0';
            num[++n] = t;
            i--;
        } else if (s[i] == '(') {
            op[++m] = s[i];
        } else if (s[i] == ')') {
            while (op[m] != '(') eval();
            m--;
        } else {
            while (m >= 0 && priority[op[m]] >= priority[s[i]])
                eval();
            op[++m] = s[i];
        }
    }
    while (m >= 0) eval();
    cout << num[n];
}
