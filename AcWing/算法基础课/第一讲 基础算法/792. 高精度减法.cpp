#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

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

int main() {
    string s1, s2;
    VI a, b, c;
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    c = sub(a, b);
    if (lt(a, b)) cout << "-";
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
