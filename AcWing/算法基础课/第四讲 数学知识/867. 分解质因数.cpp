#include <iostream>
#include <map>

using namespace std;

int n, a;

map<int, int> get_div(int x) {
    map<int, int> res;
    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) x /= i, res[i]++;
    if (x > 1) res[x]++;
    return res;
}

int main() {
    cin >> n;
    while (n-- && cin >> a) {
        for (auto [k, v]: get_div(a))
            cout << k << " " << v << endl;
        cout << endl;
    }
}
