#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/4379/

map<long long, int> ll2z;

map<long long, int> init() {
    map<long long, int> m;
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 0));
    m.insert(make_pair(2, 0));
    m.insert(make_pair(3, 0));
    m.insert(make_pair(4, 1));
    m.insert(make_pair(5, 0));
    m.insert(make_pair(6, 1));
    m.insert(make_pair(7, 0));
    m.insert(make_pair(8, 2));
    m.insert(make_pair(9, 1));
    m.insert(make_pair(10, 1));
    m.insert(make_pair(11, 2));
    m.insert(make_pair(12, 0));
    m.insert(make_pair(13, 1));
    m.insert(make_pair(14, 0));
    m.insert(make_pair(15, 0));
    return m;
}

long long num;
long long res;

int main() {
    ll2z = init();
    cin >> num;

    while (num >= 16) {
        long long y = num % (long long) (16);
        res += ll2z[y];
        num /= 16;
    }
    res += ll2z[num];

    cout << res;
}
