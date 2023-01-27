#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
string as, bs;
VI a, b, c;

void add(VI &A, VI &B, VI &C) {
    int t = 0;
    for (int i = 0; i < max(A.size(), B.size()); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
}

int main() {
    cin >> as >> bs;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');
    for (int i = bs.size() - 1; i >= 0; i--) b.push_back(bs[i] - '0');

    add(a, b, c);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
