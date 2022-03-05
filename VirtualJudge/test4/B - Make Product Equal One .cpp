#include <iostream>
using namespace std;


int main() {
    long long ans = 0;
    bool hasZero = false;  // 当有0时不需要翻转-1
    int numsLessThanZero = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long temp;
        cin >> temp;

        if (temp == 0) {
            ans += 1;
            hasZero = true;
        } else if (temp > 0) {
            ans += temp - 1;
        } else {
            ans += -temp - 1;
            numsLessThanZero += 1;
        }
    }
    if (numsLessThanZero % 2 == 1 && !hasZero)
        ans += 2;
    cout << ans;
}
