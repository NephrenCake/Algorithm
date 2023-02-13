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
    if (t) c.push_back(t);
    return c;
}

int main() {
    string s1, s2;
    VI a, b, c;
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    c = add(a, b);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
