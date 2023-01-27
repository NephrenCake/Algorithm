#include <iostream>

using namespace std;

const int N = 100010;
int n, q, a[N], tar;

int search_left() {
    int l = -1, r = n, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (a[m] < tar) l = m;
        else r = m - 1;
    }
    return r;
}

int search_right() {
    int l = -1, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (tar < a[m]) r = m;
        else l = m + 1;
    }
    return r;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        cin >> tar;
        int l = search_left(), r = search_right();
        if (l + 1 > r - 1)
            cout << -1 << " " << -1 << endl;
        else
            cout << l + 1 << " " << r - 1 << endl;
    }
}
