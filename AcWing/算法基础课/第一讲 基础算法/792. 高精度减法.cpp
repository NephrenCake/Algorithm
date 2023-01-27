#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
string as, bs;
VI a, b, c;

bool cmp(string A, string B) {
    if (A.size() != B.size())
        return A.size() > B.size();
    else return A >= B;
}

void sub(VI &A, VI &B, VI &C) {
    int t = 0;
    for (int i = 0; i < max(A.size(), B.size()); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        t = t < 0;
    }
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
}

int main() {
    cin >> as >> bs;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');
    for (int i = bs.size() - 1; i >= 0; i--) b.push_back(bs[i] - '0');

    if (cmp(as, bs))
        sub(a, b, c);
    else {
        sub(b, a, c);
        cout << "-";
    }
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
