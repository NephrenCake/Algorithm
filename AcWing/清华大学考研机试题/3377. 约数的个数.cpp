#include <iostream>

using namespace std;

int n, a;

int get_div(int x) {
    int res = 0;
    for (int i = 1; i <= x / i; i++) {
        if (i * i == x) res++;
        else if (x % i == 0) res += 2;
    }
    return res;
}

int main() {
    cin >> n;
    while (n-- && cin >> a)
        cout << get_div(a) << endl;
}
