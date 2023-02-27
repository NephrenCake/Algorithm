#include <iostream>

using namespace std;

// ����10��x�η�
int power10(int n) {
    int t = 10, res = 1;
    while (n) {
        if (n & 1) res *= t;
        t = t * t;
        n >>= 1;
    }
    return res;
}

int count(int a, int x) {
    int res = 0, len = to_string(a).size();
    for (int i = 1; i <= len; i++) {
        int l = a / power10(i), r = power10(i - 1), m = a / r % 10;
        // ע�⣬x�жϷ��㣬!x�ж�Ϊ0
        if (x) res += l * r;  // ����λΪ000~abc-1
        else res += (l - 1) * r;
        if (m > x) res += r;  // ����λ����abc
        else if (m == x) res += a % r + 1;
    }
    return res;
}

int main() {
    int a, b;
    while (cin >> a >> b, a || b) {
        if (a < b) swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << count(a, i) - count(b - 1, i) << " ";
        cout << endl;
    }
}
