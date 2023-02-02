#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
char op[N];
int num[N], n = 0, m = 0;
string s;
unordered_map<char, int> map{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };

void eval() {
    int b = num[--n], a = num[--n];
    char p = op[--m];
    // cout << a << p << b << endl;
    if (p == '+') num[n++] = a + b;
    if (p == '-') num[n++] = a - b;
    if (p == '*') num[n++] = a * b;
    if (p == '/') num[n++] = a / b;
}

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
                x = x * 10 + s[j++] - '0';
            num[n++] = x;  // Êý×ÖÈëÕ»
            i = j - 1;
        } else if (s[i] == '(') {
            op[m++] = s[i];
        } else if (s[i] == ')') {
            while (op[m - 1] != '(') eval();
            m--;
        } else {
            while (m != 0 && map[op[m - 1]] >= map[s[i]])
                eval();
            op[m++] = s[i];
        }
    }
    while (m != 0) eval();
    cout << num[0];
}
