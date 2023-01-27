#include <iostream>

using namespace std;

int n, a, ans;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        ans = 0;
        while (a) {
            a -= (a & -a);
            ans++;
        }
        cout << ans << " ";
    }
}
