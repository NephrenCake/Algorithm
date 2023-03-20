#include <iostream>

using namespace std;

const int N = 2050;
int n, a, used[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        used[a]++;
    }
    int ans = 0, cnt = used[0];
    for (int i = 1; i <= 2048; i++)
        if (cnt <= used[i])
            cnt = used[i], ans = i;
    cout << ans;
}
