#include <iostream>

using namespace std;

const int N = 100010;
int n, q, k, a[N];

int find_l(int tar) {
    int l = -1, r = n, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (a[m] < tar) l = m;
        else r = m - 1;
    }
    return r + 1;
}

int find_r(int tar) {
    int l = -1, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (tar < a[m]) r = m;
        else l = m + 1;
    }
    return r - 1;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        cin >> k;
        int l = find_l(k), r = find_r(k);
        if (l <= r && 0 <= l && l < n && 0 <= r && r < n)
            cout << l << " " << r << endl;
        else
            cout << "-1 -1" << endl;
    }
}
