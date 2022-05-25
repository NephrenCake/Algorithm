#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/4425/


int main() {
    int n;
    cin >> n;
    for (int i = 1;; i++) {
        n -= i * (i + 1) / 2;
        if (n < 0) {
            cout << i - 1;
            break;
        } else if (n == 0) {
            cout << i;
            break;
        }
    }
}
