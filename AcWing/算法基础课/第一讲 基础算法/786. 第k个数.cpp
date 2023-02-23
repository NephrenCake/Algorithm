#include <iostream>

using namespace std;

const int N = 100010;
int n, k, a[N];

int sort(int l, int r) {
    if (l == r) return a[r];
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (x < a[j]);
        if (i < j) swap(a[i], a[j]);
    }
    if (k <= j) return sort(l, j);
    else return sort(j + 1, r);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << sort(1, n);
}
