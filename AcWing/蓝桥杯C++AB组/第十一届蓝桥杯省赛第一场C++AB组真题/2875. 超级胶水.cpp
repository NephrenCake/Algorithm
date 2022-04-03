#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/2878/

/**
 * 数学题
 *      答案唯一
 *      https://www.acwing.com/solution/content/29131/
 */

int n, w;
long long ans, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w;
        ans += sum * w;
        sum += w;
    }

    cout << ans;
}
