#include <iostream>
#include <vector>

using namespace std;

string x, ans;
int m, n;

int div(vector<int> &a) {
    int t = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        t = t * m + a[i];
        a[i] = t / n;
        t = t % n;
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    return t;
}

char str(int t) {
    if (t < 10) return t + '0';
    else return t - 10 + 'a';
}

int main() {
    cin >> m >> n >> x;
    vector<int> a;
    for (int i = x.size() - 1; i >= 0; i--) {
        if ('0' <= x[i] && x[i] <= '9') a.push_back(x[i] - '0');
        else a.push_back(x[i] - 'A' + 10);
    }
    while (!(a.size() == 1 && a[0] == 0)) {
        int t = div(a);
        ans = str(t) + ans;
    }
    cout << ans;
}
