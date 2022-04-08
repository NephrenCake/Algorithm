#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/3419/

long long t, s, m, h;

int main() {
    cin >> t;
    t /= 1000;
    s = t % 60;
    m =(t / 60)  % 60;
    h = (t / 3600) % 24;
    printf("%02lld:%02lld:%02lld", h, m, s);  // 注意一定要写成lld
}
