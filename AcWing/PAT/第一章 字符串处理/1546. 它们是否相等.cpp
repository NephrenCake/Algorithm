#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1548/

const int N = 110;

struct Numbers {
    char dat[N]{};
    string valid;
    int exp = 0;
}a, b;

void parse(Numbers& number, int n) {
    bool meet_dot = false, start = false;
    int lens = strlen(number.dat);
    for (int i = 0; i < lens; i++) {
        char &c = number.dat[i];
        if (!start && c == '0' && !meet_dot)
            continue;  // ����ǰ����
        if (!start && c == '0' && meet_dot) {
            number.exp--;
            continue;  // ����С��������û�п�ʼ��Ч
        }
        if (c == '.') {
            meet_dot = true;
            continue;
        }

        start = true;
        if (number.valid.size() < n)
            number.valid += c;
        if (!meet_dot)
            number.exp++;
    }
    while (number.valid.size() < n)
        number.valid += '0';
    if (!start)
        number.exp = 0;
}

int main() {
    int n;
    cin >> n >> a.dat >> b.dat;
    parse(a, n);
    parse(b, n);
    if (a.valid == b.valid && a.exp == b.exp)
        cout << "YES 0." << a.valid << "*10^" << a.exp;
    else
        cout << "NO 0." << a.valid << "*10^" << a.exp << " 0." << b.valid << "*10^" << b.exp;
}
