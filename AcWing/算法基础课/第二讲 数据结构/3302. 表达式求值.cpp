#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int num[N], ttn = -1, tto = -1;
char ops[N];
unordered_map<char, int> prio = {{'+', 1},
                                 {'-', 1},
                                 {'*', 2},
                                 {'/', 2}};

void eval() {
    int b = num[ttn--], a = num[ttn--], op = ops[tto--];
    if (op == '+') num[++ttn] = a + b;
    if (op == '-') num[++ttn] = a - b;
    if (op == '*') num[++ttn] = a * b;
    if (op == '/') num[++ttn] = a / b;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i])) {
            int t = 0;
            while (isdigit(s[i])) t = t * 10 + s[i++] - '0';
            i--;
            num[++ttn] = t;
        } else if (s[i] == '(') ops[++tto] = s[i];
        else if (s[i] == ')') {
            while (ops[tto] != '(') eval();
            tto--;
        } else {
            while (prio[ops[tto]] >= prio[s[i]]) eval();  // 注意同级也要计算
            ops[++tto] = s[i];
        }
    while (0 <= tto) eval();
    cout << num[0];
}
