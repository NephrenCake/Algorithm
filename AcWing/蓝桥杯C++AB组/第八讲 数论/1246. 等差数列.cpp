#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/1248/

const int N = 100010;

int arr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int d = 0, M = arr[0], m = arr[0];
    for (int i = 1; i < n; i++) {
        d = gcd(d, abs(arr[i] - arr[i - 1]));
        M = max(M, arr[i]);
        m = min(m, arr[i]);
        // cout << d << endl;
    }
    if (!d)
        cout << n;
    else
        cout << (M - m) / d + 1;
}
