#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
string as;
VI a, c;
int b;

void mul(VI &A, int B, VI &C) {
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
}

int main() {
    cin >> as >> b;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');

    mul(a, b, c);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
}
