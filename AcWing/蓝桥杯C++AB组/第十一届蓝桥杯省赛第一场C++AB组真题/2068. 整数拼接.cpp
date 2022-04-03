#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/2070/

// k | arr[j] * 10^ki arr[i]
// (arr[j] * 10^ki arr[i]) % k == 0
// arr[j] * 10^ki % k == -arr[i] % k

typedef long long LL;
const int N = 1e5 + 10;

int arr[N];  // 给定一个长度为 n 的数组 A1,A2,,An。
int n, k;
LL ans, temp;
int s[11][N];

LL cal(int a, LL b, int c) {
    b %= c;
    while (a != 0) {
        a /= 10;
        b *= 10;
    }
    return b;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        LL t = arr[i] % k;
        for (int j = 0; j < 11; j++) {
            s[j][t]++;
            t = t * 10 % k;
        }
    }

    for (int i = 0; i < n; i++) {
        LL t = arr[i] % k;
        int len = to_string(arr[i]).size();
        ans += s[len][(k - t) % k];

        LL r = t;
        while (len--)
            r = r * 10 % k;
        if (r == (k - t) % k)
            ans--;
    }
    cout << ans;
}
