#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/3493/

const int N = 10010;

int n, ans;

int main() {
    cin >> n;

    for (int v = 1; v < n; v++) {
        double comp = (double )n / 2;
        if (v * v % n < comp)
            ans++;
    }

    cout << ans;
}
