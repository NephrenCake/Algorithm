#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, k, a[N], q[N], hh = 0, tt = -1;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        while (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if (i + 1 >= k)
            cout << a[q[hh]] << " ";
    }
    cout << endl;
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        while (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i + 1 >= k)
            cout << a[q[hh]] << " ";
    }
}
