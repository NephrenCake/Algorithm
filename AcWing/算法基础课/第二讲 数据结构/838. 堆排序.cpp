#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, a[N];

void down(int i) {
    int t = i;
    if (i * 2 <= n && a[t] > a[i * 2])
        t = i * 2;
    if (i * 2 + 1 <= n && a[t] > a[i * 2 + 1])
        t = i * 2 + 1;
    if (t != i) {
        swap(a[i], a[t]);
        down(t);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = n / 2;  i >= 1; i--) down(i);
    while (m--) {
        cout << a[1] << " ";
        swap(a[1], a[n]);
        n--;
        down(1);
    }
}
