#include <iostream>

using namespace std;

const int N = 100010;
int n, a[N];

void sort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (x < a[j]);
        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    sort(l, j);
    sort(j + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
