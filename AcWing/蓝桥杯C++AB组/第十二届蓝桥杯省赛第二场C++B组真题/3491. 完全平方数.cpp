#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

// https://www.acwing.com/problem/content/3494/

/**
 * 分解质因数模板题
 */

long long n, ans = 1;

int main() {
    cin >> n;

    for (long long i = 2; i * i <= N; ++i) {
        while (n % i == 0) {
            if (n % (i * i) == 0)
                n /= (i * i);
            else
                n /= i, ans *= i;
        }
    }
    if (n > 1)
        ans *= n;
    cout << ans;
}
