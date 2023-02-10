#include <iostream>

using namespace std;

int n;

void divide(int a) {
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) a /= i, cnt++;
            cout << i << " " << cnt << endl;
        }
    }
    if (a > 1) cout << a << " 1" << endl;
    cout << endl;
}

int main() {
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        divide(a);
    }
}
