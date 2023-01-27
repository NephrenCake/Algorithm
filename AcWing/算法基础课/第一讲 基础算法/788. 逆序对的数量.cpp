#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010;
int n, a[N], t[N];

LL mergeSort(int l, int r) {
    if (l == r) return 0;

    int m = (l + r) / 2;
    LL res = mergeSort(l, m) + mergeSort(m + 1, r);

    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else {
            t[k++] = a[j++];
            res += m - i + 1;
        }
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (int i = 0; i < k; i++) a[l++] = t[i];
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << mergeSort(0, n - 1) << endl;
}
