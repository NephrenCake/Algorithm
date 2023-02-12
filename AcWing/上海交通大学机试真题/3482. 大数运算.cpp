#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI add(VI &a, VI &b) {
    VI c;
    int t = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t % 10);
    return c;
}

bool lt(VI &a, VI &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

VI sub(VI &a, VI &b) {
    if (lt(a, b))
        return sub(b, a);
    VI c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i];
        if (i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        t = t < 0 ? -1 : 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

VI mul(VI &a, VI &b) {
    VI c = VI(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    int t = 0;
    for (int i = 0; i < c.size(); i++) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

void printVI(VI &a, bool neg) {
    if (neg) cout << '-';
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];
    cout << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    VI a, b, c;
    for (int i = s1.size() - 1; i >= 0; i--)
        if (s1[i] != '-') a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--)
        if (s2[i] != '-') b.push_back(s2[i] - '0');

    if (s1[0] != '-' && s2[0] != '-') {
        c = add(a, b);
        printVI(c, false);
        c = sub(a, b);
        printVI(c, lt(a, b));
        c = mul(a, b);
        printVI(c, false);
    } else if (s1[0] != '-' && s2[0] == '-') {
        c = sub(a, b);
        printVI(c, lt(a, b));
        c = add(a, b);
        printVI(c, false);
        c = mul(a, b);
        printVI(c, true);
    } else if (s1[0] == '-' && s2[0] != '-') {
        c = sub(b, a);
        printVI(c, lt(b, a));
        c = add(a, b);
        printVI(c, true);
        c = mul(a, b);
        printVI(c, true);
    } else if (s1[0] == '-' && s2[0] == '-') {
        c = add(a, b);
        printVI(c, true);
        c = sub(b, a);
        printVI(c, lt(b, a));
        c = mul(a, b);
        printVI(c, false);
    }
}
