#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI div(VI &A, int b, int &r) {
    VI C = VI(A.size(), 0);
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C[i] = r / b;
        r %= b;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    VI A, C;
    int b, r;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl << r;
}
