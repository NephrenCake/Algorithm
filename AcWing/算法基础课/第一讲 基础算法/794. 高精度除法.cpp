#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI div(VI &a, int b, int &r) {
    VI c = VI(a.size(), 0);
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        c[i] = r / b;
        r %= b;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    string s1;
    int b, d;
    VI a, c;
    cin >> s1 >> b;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');

    c = div(a, b, d);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl << d;
}
