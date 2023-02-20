#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI mul(VI &a, int b) {
    for (int i = 0; i < a.size(); i++) a[i] *= b;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i];
        a[i] = t % 10;
        t /= 10;
    }
    while (t) a.push_back(t % 10), t /= 10;
    return a;
}

int main() {
    int n;
    VI ans[1001] = {{1}, {1}}, tmp = {1};
    for (int i = 2; i <= 1000; i++)
        ans[i] = mul(tmp, i);
    while (cin >> n) {
        for (int i = ans[n].size() - 1; i >= 0; i--)
            cout << ans[n][i];
        cout << endl;
    }
}
