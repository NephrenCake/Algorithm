#include<bits/stdc++.h>

using namespace std;

int a[4];
char t;
long long ans;

int main() {
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    while (scanf("%c", &t) != -1) {
        ans += a[t - '1'];
    }
    cout << ans;
}