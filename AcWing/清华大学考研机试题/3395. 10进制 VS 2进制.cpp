#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

void inc(VI &a) {
    a[0]++;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i];
        a[i] = t % 10;
        t /= 10;
    }
}

void mul(VI &a, int b, VI &c) {
    c = VI(a.size(), 0);
    int t = 0;
    for (LL i = 0; i < a.size(); i++) {
        t = t + a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
}

void div(VI &a, int b, VI &c, int &t) {
    c = VI(a.size(), 0);
    t = 0;
    for (LL i = a.size() - 1; i >= 0; i--) {
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
}

bool isZero(VI &a) {
    return a.size() == 1 && a[0] == 0;
}

int main() {
    string s, ab, bb;
    cin >> s;
    VI ah, bh = {0}, t;
    int r;
    for (int i = s.size() - 1; i >= 0; i--) ah.push_back(s[i] - '0');
    while (!isZero(ah)) {
        div(ah, 2, t, r);
        ah = t;
        ab = ab + to_string(r);
    }
    for (int i = 0; i < ab.size(); i++) {
        mul(bh, 2, t);
        bh = t;
        if (ab[i] == '1') inc(bh);
    }
    for (int i = bh.size() - 1; i >= 0; i--)
        cout << bh[i];
}
