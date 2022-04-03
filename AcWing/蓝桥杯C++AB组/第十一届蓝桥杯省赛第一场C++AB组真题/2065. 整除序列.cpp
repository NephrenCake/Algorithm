#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/2067/

long long n;

int main() {
    cin >> n;
    while (n != 0) {
        printf("%lld ", n);
        n /= 2;
    }
}
