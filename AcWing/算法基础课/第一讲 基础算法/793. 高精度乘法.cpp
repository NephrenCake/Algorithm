#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

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

int main() {
    string s1, s2;
    VI a, b, c;
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    c = mul(a, b);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
