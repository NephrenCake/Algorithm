#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
string as;
VI a, c;
int b, r;

void div(VI &A, int B, VI &C, int &R) {
    int t = 0;
    C = A;
    for (int i = A.size() - 1; i >= 0; i--) {
        t = t * 10 + A[i];
        C[i] = t / B;
        t %= B;
    }
    while (C.size() > 1 && C[C.size() - 1] == 0) C.pop_back();
    R = t;
}

int main() {
    cin >> as >> b;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');

    div(a, b, c, r);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl << r;
}
